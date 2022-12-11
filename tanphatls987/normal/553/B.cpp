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
const int N=60;

int n;
ll k,f[N];
int main(){
    cin>>n>>k;
    f[0]=1;f[1]=1;
    FOR(i,2,n) f[i]=f[i-1]+f[i-2];
    for(int i=1;i<=n;i++){
        if (f[n-i]<k){
            k-=f[n-i];
            i++;
            printf("%d %d ",i,i-1);
        }else printf("%d ",i);
    }
}