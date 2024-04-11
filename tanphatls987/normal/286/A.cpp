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
const int N=1e5+10;

int p[N];
void solve(int n){
    if (n%4==2||n%4==3){
        printf("-1");
        return;
    }
    if (n%4==1) p[(n+1)/2]=(n+1)/2;
    for(int i=1;i<=n/2;i+=2){
        p[i]=i+1;
        int cur=i;
        FOR(j,0,2){
            p[p[cur]]=n-cur+1;
            cur=p[cur];
        }
    }
    FOR(i,1,n) printf("%d ",p[i]);
}
int main(){
    int n;
    cin>>n;
    solve(n);
}