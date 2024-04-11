#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=3507;
int n,m,k;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n>>m>>k;
        k=min(k,m-1);
        for (int i=1;i<=n;++i) cin>>a[i];
        int ans=0;
        for (int i=0;i<=k;++i){
            int ret=1e9;
            for (int j=0;j<m-k;++j){
                ret=min(ret,max(a[i+j+1],a[n-(k-i)-(m-k-1-j)]));
            }
            ans=max(ans,ret);
        }
        cout<<ans<<endl;
    }
    return 0;
}