#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0,alp=26;

int n,h[alp],f[alp][alp],f0[alp];
string s;
int main(){
    cin>>n;
    FOR(i,1,n){
        memset(h,0,sizeof(h));
        cin>>s;
        for(auto c:s) h[c-'a']++;
        int c=alp-count(h,h+alp,0);
        if (c>2) continue;
        int idx=0;
        while (!h[idx]) idx++;
        if (c==2){
            int nidx=alp-1;
            while (!h[nidx]) nidx--;
            f[idx][nidx]+=h[nidx]+h[idx];
        }else f0[idx]+=h[idx];
    }
    int ans=0;
    REP(i,0,alp)
        REP(j,i+1,alp) ans=max(ans,f[i][j]+f0[i]+f0[j]);
    cout<<ans;
}