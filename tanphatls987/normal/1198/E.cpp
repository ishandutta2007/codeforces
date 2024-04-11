#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e3 + 10;
const int M = 1e5 + 10;
const int inf = 1e9 + 10;

int m;
int n[2];
int a[200][200];
int b[100][4];
vector<int> coor[2];

struct maxflow{
    int n,m,st,en;
    ///st is the source node
    ///en is the sink node
    int v[M][2],flow[M][2],cap[M];
    int f[N];
    int t[N];
    vector<int> e[N];
    void build(int _n,int _st,int _en){
        n=_n;st=_st;en=_en;
        m=0;
        for(int i=1;i<=n;i++) e[i].clear();
    }
    void add_edge(int x,int y,int _cap){
        ++m;
        v[m][0]=x;v[m][1]=y;
        e[x].push_back(m);
        e[y].push_back(m);
        cap[m]=_cap;
        flow[m][0]=0;
        flow[m][1]=_cap;
    }


    int inc_flow(){
        ///modified the network along the found path
        int ans=f[en];
        int cur=en;
        while (cur!=st){
            ///find the previous edge
            int idx=t[cur];
            int dir=(v[idx][0]==cur);
            flow[idx][dir]+=ans;
            flow[idx][dir^1]-=ans;
            cur=v[idx][dir];
        }
        return ans;
    }
    queue <int> q;
    bool BFS(){
        ///return whether there exist a augment path

        ///reset initial state
        fill(t+1,t+n+1,0);
        t[st]=-1;
        f[st]=inf;
        q.push(st);
        while (!q.empty()){
            int x=q.front();q.pop();
            for(int i=0;i<e[x].size();i++){
                int idx=e[x][i];
                ///find the current direction
                int dir=(x==v[idx][1]);
                ///saturated edge
                if (flow[idx][dir]==cap[idx]) continue;
                int y=v[idx][dir^1];
                if (t[y]) continue;
                ///f[y] equal the maximum flow we can send from st to y
                ///t[y] is the last edge from st to y
                ///idx>0 so the condition that t[y]!=0 is true after those lines below
                t[y]=idx;
                f[y]=min(f[x],cap[idx]-flow[idx][dir]);
                q.push(y);
            }
        }
        ///if there is a path , t[en] should be different than 0
        return t[en];
    }
    int answer(){
        int ans=0;
        while (BFS()) ans+=inc_flow();
        return ans;
    }
}mgraph;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tmp;
    cin >> tmp >> m;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 4; j++) cin >> b[i][j];
        for(int j = 0; j < 4; j++) {
            b[i][j] += j / 2;
            coor[j % 2].push_back(b[i][j]);
        }
    }
    for(int i = 0; i < 2; i++) {
        sort(coor[i].begin(), coor[i].end());
        n[i] = unique(coor[i].begin(), coor[i].end()) - coor[i].begin();
        coor[i].resize(n[i]);
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 4; j++) {
            int dir = j % 2;
            b[i][j] = lower_bound(coor[dir].begin(), coor[dir].end(), b[i][j]) - coor[dir].begin() + 1;
        }
        for(int x = b[i][0]; x < b[i][2]; x++)
            for(int y = b[i][1]; y < b[i][3]; y++) 
                a[x][y] = 1;
    }
    mgraph.build(n[0] + n[1] + 2, n[0] + n[1] + 1, n[0] + n[1] + 2);
    for(int i = 1; i <= n[0]; i++) 
        mgraph.add_edge(mgraph.st, i, coor[0][i] - coor[0][i - 1]);
    for(int i = 1; i <= n[1]; i++) {
        mgraph.add_edge(n[0] + i, mgraph.en, coor[1][i] - coor[1][i - 1]);
    }
    int inf = 1e9 + 10;
    for(int i = 1; i <= n[0]; i++)
        for(int j = 1; j <= n[1]; j++) if (a[i][j]) {
            mgraph.add_edge(i, n[0] + j, inf);
        }
    cout << mgraph.answer();

}