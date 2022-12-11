#include <bits/stdc++.h>

using namespace std;


int n;
char a[10][4][40][5];

void prepare() {
    for(int i1 = 0; i1 < 10; i1++)
        for(int i2 = 0; i2 < 4; i2++)
            for(int i3 = 0; i3 < 40; i3++)
                for(int i4 = 0; i4 < 5; i4++) a[i1][i2][i3][i4] = '.';
    for(int i = 0; i < 10; i++) {
        for(int y = 0; y < 5; y++)
            for(int x = 0; x < 40; x++) a[i][3][x][y] = '#';
        for(int room = 0; room < 10; room++) { 
            int st = room * 4;
            for(int j = 0; j < 4; j++) 
                for(int lv = 0; lv < 3; lv++) 
                    a[i][lv][st + j][3] = a[i][lv][st + 3][j] = '#';
        }
    }
}

vector<vector<int>> gr;

stack<int> s;
int v[12][12];
int low[12], num[12];
void DFS(int x) {
    static int n1 = 0;
    low[x] = num[x] = ++n1;
    s.push(x);
    for(int y = 1; y <= n; y++) if (v[x][y] && num[y] != -1) {
        if (num[y]) low[x] = min(low[x], num[y]);
        else {
            DFS(y);
            low[x] = min(low[x], low[y]);
        }
    }
    //cout << x << " " << low[x] << " " << num[x] << '\n';
    if (low[x] >= num[x]) {
        //cout << " ?  " << x << '\n';
        gr.push_back(vector<int>()); 
        while (s.top() != x) {
            num[s.top()] = -1;
            gr.back().push_back(s.top());
            s.pop();
        }
        num[x] = -1;
        gr.back().push_back(x);
        s.pop();
    }
}

vector<int> vg[12];
vector<int> topo;
void tarzan() {
    for(int i = 1; i <= n; i++) if (!num[i]) DFS(i);
    
    ///mark scc
    int com[12];
    for(int ng = 0; ng < gr.size(); ng++) {
        for(auto j : gr[ng]) com[j] = ng + 1;
    }
   
    ///build degree arr
    int deg[12];
    memset(deg, 0, sizeof(deg));
    for(int x = 1; x <= n; x++) 
        for(int y = 1; y <= n; y++) if (v[x][y]) {
            if (com[x] == com[y]) continue;
            //cout << com[x] << "->" << com[y] << '\n';
            vg[com[x]].push_back(com[y]);
            deg[com[y]]++;
        }
    

    ///topo sort
    queue<int> qg;
    for(int x = 1; x <= gr.size(); x++) if (!deg[x]) qg.push(x);
    while (!qg.empty()) {
        int x = qg.front(); qg.pop();
        topo.push_back(x);
        for(auto y : vg[x]){
            deg[y]--;
            if (!deg[y]) qg.push(y);
        }
    }
}
void place(int lv, int num) {
    int st = (num - 1) * 4;
    
    vector<int>& per = gr[num - 1];

    ///make hole from above
    for(int i = 0; i < lv; i++) a[i][3][st][0] = '.';

    ///put all person in same group
    for(int i1 = 0; i1 < 3; i1++)
        for(int i2 = 0; i2 < 3; i2++) if (i1 * 3 + i2 < per.size()){
            a[lv][2][st + i1][i2] = per[i1 * 3 + i2] + '0';
        }
    ///make gate
    a[lv][2][st][3] = '.';
    for(auto tar : vg[num]) a[lv][2][(tar - 1) * 4][3] = '.';
}
int main() {
    prepare();
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) cin >> v[i][j];
    tarzan();
    
    /*
    for(auto i : gr) {
        cout << i.size() << '\n';
        for(auto j : i) cout << j << " ";
        cout << '\n';
    }

    cout << "topo\n";
    for(auto i : topo) cout << i <<  " ";
    cout << '\n';
    */
    
    for(int lv = 0; lv < topo.size(); lv++)
        place(lv, topo[lv]);

    cout << "5 40 40\n";
    for(int lv = 0; lv < 10; lv++)
        for(int lay = 0; lay < 4; lay++) {
            for(int x = 0; x < 40; x++) {
                for(int y = 0; y < 5; y++) cout << a[lv][lay][x][y];
                cout << '\n';
            }
            cout << '\n';
        }

}