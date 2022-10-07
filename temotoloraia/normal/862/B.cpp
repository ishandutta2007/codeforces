#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005;
int n;
vector<int> g[N];
LL ans;
void DFS (int k, int p, LL x){
    ans+=x;
    for (int i = 0; i < (int)g[k].size(); i++)
        if (g[k][i] != p)
            DFS (g[k][i], k, 1-x);
}
int main() {
    cin>>n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    DFS (1, 0, 0);
    cout<<ans*(n-ans)-n+1<<endl;
	return 0;
}