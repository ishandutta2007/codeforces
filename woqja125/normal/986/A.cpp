#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int c[100001];
vector<int> map[100001];
int d[100001][101];
int main(){
    int n, m, k, s, a, b;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for(int i=1; i<=n; i++) scanf("%d", c+i);
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for(int C=1; C<=k; C++){
        queue<int> Q;
        for(int i=1; i<=n; i++){
            if(c[i] == C){
                d[i][C] = 0;
                Q.push(i);
            }
            else d[i][C] = -1;
        }
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for(auto e:map[x]){
                if(d[e][C] == -1){
                    d[e][C] = d[x][C] + 1;
                    Q.push(e);
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        int ans = 0;
        sort(d[i]+1, d[i]+k+1);
        for(int j=1; j<=s; j++) ans += d[i][j];
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}