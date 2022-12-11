#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=3e3+10;

int a[N],n;
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int ans=0;
    FOR(i,1,n) if (a[i]){
        int c1=0,c2=0;
        FOR(j,i+1,n) if (abs(a[j])<abs(a[i])){
            if (a[i]<a[j]) c2++;
            else c1++;
        }
        FORD(j,i-1,1) if (abs(a[j])<abs(a[i])){
            if (a[i]<a[j]) c1++;
            else c2++;
        }
        ans+=min(c1,c2);
        //else ans+=min(c4+c1,c3+c2);
    }
    cout<<ans;
}