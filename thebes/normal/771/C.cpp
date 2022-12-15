#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5+5;
ll cnt[MN][5], h[MN][5], n, k, i, x, y, ans, s[5], t[5];
vector<int> adj[MN];

void solve(int n,int p){
    cnt[n][0] = 1;
    for(auto v : adj[n]){
        if(v == p) continue;
        solve(v, n);
        h[v][k-1] += cnt[v][k-1];
        for(int i=0;i<k;i++){
            s[i]=cnt[v][(i+k-1)%k];
            t[i]=h[v][(i+k-1)%k];
        }
        for(int i=0;i<k;i++){
            cnt[v][i] = s[i];
            h[v][i] = t[i];
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                ans += ceil((i+j)/(double)k)*cnt[n][i]*cnt[v][j];
				ans += h[n][i]*cnt[v][j]+h[v][j]*cnt[n][i];
            }
        }
        for(int i=0;i<k;i++){
            cnt[n][i] += cnt[v][i];
            h[n][i] += h[v][i];
        }
    }
}

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(1, 0);
    printf("%lld\n",ans);
    return 0;
}