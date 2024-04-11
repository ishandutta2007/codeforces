#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=6050;

int n,h[N]={0};
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x;
        scanf("%d",&x);
        h[x]++;
    }
    int ans=0;
    FOR(i,1,2*n) if (h[i]>1){
        ans+=h[i]-1;
        h[i+1]+=h[i]-1;
    }
    cout<<ans;
}