#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("225e.inp","r",stdin)
#define OUTPUT freopen("225e.out","w",stdout)
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
const int d[40]={2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};

int main(){
    int n;
    cin>>n;
    int ans=0;
    REP(i,1,d[n-1]) ans=(2*ans+1)%MOD;
    cout<<ans;
}