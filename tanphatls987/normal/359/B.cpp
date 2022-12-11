#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("359.inp","r",stdin)
#define OUTPUT freopen("359.out","w",stdout)
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
const int N=0;

int main(){
    int n,k;
    cin>>n>>k;
    REP(i,0,k) printf("%d %d ",2*i+1,2*i+2);
    REP(i,k,n) printf("%d %d ",2*i+2,2*i+1);
}