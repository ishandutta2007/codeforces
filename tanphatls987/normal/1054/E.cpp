#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 3e2 + 10;

vector<int> ans[4];

void record(int xa, int ya, int xb, int yb){
    ans[0].push_back(xa);
    ans[1].push_back(ya);
    ans[2].push_back(xb);
    ans[3].push_back(yb);
}
int n,m;
string s1[N][N], s2[N][N];
struct {
    deque<int> qc[N][N]; 

    void push(int i, int j, int ch){
        qc[i][j].push_front(ch);
    }
    int pop(int i, int j){
        int ch = qc[i][j].back();
        qc[i][j].pop_back();
        return ch;
    }
    int get(int i, int j){
        return qc[i][j].back();
    }
    void move(int xa, int ya, int xb, int yb){
        assert(!qc[xa][ya].empty());
        assert((xa == xb || ya == yb) && (xa != xb || ya != yb));
        int ch = pop(xa, ya);
        push(xb, yb, ch);
        record(xa, ya, xb, yb);
    }
}b1;

void phase1(){
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= m; j++) if (3 - i != j){
            while (!b1.qc[i][j].empty()){
                b1.move(i, j, i, 3 - i);
            }
        }
    }
    for(int j = 1; j <= 2; j++)
        for(int i = 3; i <= n; i++){
            while (!b1.qc[i][j].empty()){
                b1.move(i, j, 3 - j, j);
            }
        }
    for(int i = 1; i <= 2; i++){
        int j = 3 - i;
        while (!b1.qc[i][j].empty()){
            int ch = b1.get(i, j);
            int ni = ch + 1, nj = ch + 1;
            b1.move(i, j, ni, nj);
        }
    }
    for(int i = 3; i <= n; i++){
        for(int j = 3; j <= m; j++){
            while (!b1.qc[i][j].empty()){
                int ch = b1.get(i, j);
                b1.move(i, j, i, ch + 1);
                b1.move(i, ch + 1, ch + 1, ch + 1);
            }
        }
    }
}
void phase2(){
    int need00 = count(s2[1][1].begin(), s2[1][1].end(), '0');
    int need01 = count(s2[1][1].begin(), s2[1][1].end(), '1');
    while (need00--) b1.move(1,1,1,2);
    while (need01--) b1.move(2,2,2,1);
    for(int k = int(s2[1][1].size()) - 1; k >= 0; k--){
        int use = s2[1][1][k] - '0';
        if (use == 0) b1.move(1,2,1,1);
        else b1.move(2,1,1,1);
    }
    
    int need10 = count(s2[2][2].begin(), s2[2][2].end(), '0');
    int need11 = count(s2[2][2].begin(), s2[2][2].end(), '1');
    while (need10--) b1.move(1,1,1,2);
    while (need11--) b1.move(2,2,2,1);
    for(int k = int(s2[2][2].size()) - 1; k >= 0; k--){
        int use = s2[2][2][k] - '0';
        if (use == 0) b1.move(1,2,2,2);
        else b1.move(2,1,2,2);
    }

    int n12 = s2[1][2].size();
    for(int k = n12 - 1; k >= 0; k--) {
        int need = s2[1][2][k] - '0';
        b1.move(need + 1, need + 1, 1, 2);
    }
    int n21 = s2[2][1].size();
    for(int k = n21 - 1; k >= 0; k--) {
        int need = s2[2][1][k] - '0';
        b1.move(need + 1, need + 1, 2, 1);
    }
}
void phase3(){
    int needr1 = 0;
    for(int j = 3; j <= m; j++) needr1 += count(s2[1][j].begin(), s2[1][j].end(), '1');
    while (needr1--)
        b1.move(2,2,1,2);
    for(int j = 3; j <= m; j++){
            int n1 = s2[1][j].size();
            for(int k = n1 - 1; k >= 0; k--) {
                int need = s2[1][j][k] - '0';
                b1.move(1, need + 1, 1, j);
            }
    }
    int needc1 = 0;
    for(int i = 3; i <= n; i++) needc1 += count(s2[i][1].begin(), s2[i][1].end(), '1');
    while (needc1--)
        b1.move(2,2,2,1);
    for(int i = 3; i <= n; i++){
            int n1 = s2[i][1].size();
            for(int k = n1 - 1; k >= 0; k--) {
                int need = s2[i][1][k] - '0';
                b1.move(need + 1, 1, i, 1);
            }
    }
    int needr0 = 0;
    for(int j = 3; j <= m; j++) needr0 += count(s2[2][j].begin(), s2[2][j].end(), '0');
    while (needr0--)
        b1.move(1,1,2,1);
    for(int j = 3; j <= m; j++){
            int n1 = s2[2][j].size();
            for(int k = n1 - 1; k >= 0; k--) {
                int need = s2[2][j][k] - '0';
                b1.move(2, need + 1, 2, j);
            }
    }
    int needc0 = 0;
    for(int i = 3; i <= n; i++) needc0 += count(s2[i][2].begin(), s2[i][2].end(), '0');
    while (needc0--)
        b1.move(1,1,1,2);
    for(int i = 3; i <= n; i++){
            int n1 = s2[i][2].size();
            for(int k = n1 - 1; k >= 0; k--) {
                int need = s2[i][2][k] - '0';
                b1.move(need + 1, 2, i, 2);
            }
    }
}
void phase4(){
    for(int i = 3; i <= n; i++){
        for(int j = 3; j <= m; j++){
            int n0 = count(s2[i][j].begin(), s2[i][j].end(), '0');
            int n1 = count(s2[i][j].begin(), s2[i][j].end(), '1');
            while (n0--) b1.move(1,1,i,1);
            while (n1--) b1.move(2,2,2,j);

            for(int k = int(s2[i][j].size()) - 1; k >= 0; k--) {
                int need = s2[i][j][k] - '0';
                if (need == 0)
                    b1.move(i, 1, i, j);
                else b1.move(2, j, i, j);
            }
        }
    }
}

bool comp(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            string s;
            while (!b1.qc[i][j].empty()){
                s.push_back('0' + b1.qc[i][j].front());
                b1.qc[i][j].pop_front();
            }
            //cout << i <<" "<< j << " "<< s << " " << s2[i][j]<<'\n';
            if (s != s2[i][j]) return 0;
        }
    return 1;
}
void solve(){
    phase1();
    phase4();
    phase3();
    phase2();
    assert(comp());
    cout << ans[0].size() <<'\n';
    for(int i = 0; i < ans[0].size(); i++)
        for(int j = 0; j < 4; j++) cout << ans[j][i] << " \n"[j==3];
}
void prepare() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> s1[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> s2[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) 
            for(int pos = int(s1[i][j].size()) - 1; pos >= 0; pos--){
                b1.push(i, j, s1[i][j][pos] - '0');
            }
    }
}
int main() {
    prepare();
    solve();
}