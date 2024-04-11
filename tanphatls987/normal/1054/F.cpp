#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n;
int a[N][2];
int ans[2][N];
int py[N], px[N];
struct {
    int n1, n2;
    int match[2][N];
    int h[2][N];
    vector<int> v[N];

    void add_edge(int x, int y){
        //cout << "Edge:" << x << " " << y << '\n';
        v[x].push_back(y);
    }

    bool DFS(int x){
        h[0][x] = 1;
        for(auto y : v[x]){
            if (h[1][y] == 1) continue;
            if (y == match[0][x]) continue;
            h[1][y] = 1;
            if ((match[1][y] == -1) || DFS(match[1][y])){
                match[0][x] = y;
                match[1][y] = x;
                return 1;
            }
        }
        return 0;
    }
    int q[N];
    int get(){
        int top = 1, bot = n1;
        for(int i = 1; i <= n1; i++){
            q[i] = i;
        }
        memset(match, -1, sizeof(match));
        while (1){
            memset(h, 0, sizeof(h));
            bool okay = 0;
            for(int i = top; i <= bot; i++){
                if (DFS(q[i])){
                    okay = 1;
                    swap(q[i--], q[bot--]);
                }
            }
            if (!okay) break;
        }
        for(int i = 1; i <= n2; i++){
            ans[1][i] = (match[1][i] != -1 && h[1][i]); 
        }
        for(int i = 1; i <= n1; i++) {
            ans[0][i] = (match[0][i] != -1 && !ans[1][match[0][i]]);
        }
        return bot;
    }
}match;

struct line{
    int x, L, R;
    line (int x, int L, int R)
        : x(x),L(L),R(R){}
};
vector<line> xline, yline;
bool cross(line a, line b){
    return (b.L <= a.x && b.R >= a.x && a.L <= b.x && a.R >= b.x);
}

set<pair<int,int>> mset;
void prepare() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    for(int i = 1; i <= n; i++) mset.insert(make_pair(a[i][0], a[i][1]));

    for(int i = 1; i <= n; i++) px[i] = i;
    sort(px + 1, px + n + 1, 
        [](int x, int y){
            if (a[x][0] == a[y][0]) return a[x][1] < a[y][1];
            return a[x][0] < a[y][0];
    });
    for(int i = 1; i <= n; i++) py[i] = i;
    sort(py + 1, py + n + 1, 
        [](int x, int y){
            if (a[x][1] == a[y][1]) return a[x][0] < a[y][0];
            return a[x][1] < a[y][1];
    });
    for(int i = 1; i < n; i++) if (a[px[i]][0] == a[px[i + 1]][0]){
        int L = a[px[i]][1], R = a[px[i + 1]][1];
        xline.push_back(line(a[px[i]][0], L, R));
    }
    for(int i = 1; i < n; i++) if (a[py[i]][1] == a[py[i + 1]][1]){
        int L = a[py[i]][0], R = a[py[i + 1]][0];
        yline.push_back(line(a[py[i]][1], L, R));
    }
    match.n1 = xline.size();
    match.n2 = yline.size();
    for(int i = 0; i < xline.size(); i++)
        for(int j = 0; j < yline.size(); j++) if (cross(xline[i], yline[j])){
            if (!mset.count(make_pair(xline[i].x, yline[j].x)))
                match.add_edge(i + 1, j + 1);
        }
    //for(auto i : xline) cout << i.x << " " << i.L << " " << i.R <<'\n';
    //for(auto i : yline) cout << i.x << " " << i.L << " " << i.R <<'\n';
}

int rans[N];
void solveX(){
    memset(rans, 0, sizeof(rans));
    for(int en = 0; en < xline.size(); en++) if (!ans[0][en + 1]){
        int xa = xline[en].x, ya = xline[en].L;
        int L = 1, R = n;
        while (L <= R){
            int mid = (L + R) / 2;
            bool okay = (xa != a[px[mid]][0]) ? xa < a[px[mid]][0] :
                ya < a[px[mid]][1];
            if (okay) R = mid - 1;
            else L = mid + 1;
        }
        rans[R] = 1;
    }
    vector<line> xans;
    for(int en = 1; en <= n; en++) {
        int st = en;
        while (rans[en]) en++;
        xans.push_back(line(a[px[st]][0], a[px[st]][1], a[px[en]][1]));
    }
    cout << xans.size() << '\n';
    for(auto i : xans) cout << i.x << " " << i.L << " " << i.x << " " << i.R << '\n';
}
void solveY() {
    memset(rans, 0, sizeof(rans));
    for(int en = 0; en < yline.size(); en++) if (!ans[1][en + 1]){
        int xa = yline[en].L, ya = yline[en].x;
        int L = 1, R = n;
        while (L <= R){
            int mid = (L + R) / 2;
            bool okay = (ya != a[py[mid]][1]) ? ya < a[py[mid]][1] :
                xa < a[py[mid]][0];
            if (okay) R = mid - 1;
            else L = mid + 1;
        }
        rans[R] = 1;
    }
    vector<line> yans;
    for(int en = 1; en <= n; en++) {
        int st = en;
        while (rans[en]) en++;
        yans.push_back(line(a[py[st]][1], a[py[st]][0], a[py[en]][0]));
    }
    cout << yans.size() << '\n';
    for(auto i : yans) cout << i.L << " " << i.x << " " << i.R << " " << i.x << '\n';
}
void solve() {
    match.get();
    solveY();
    solveX();
}
int main() {
    prepare();
    solve();
}