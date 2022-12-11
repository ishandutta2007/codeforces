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
const int N=1e5+10;

int n,a[N];
void solve(){
    a[0]=1;
    if (a[n]){
        printf("NO");
        return;
    }
    if (a[n-1]) {
        printf("YES\n");
        FOR(i,1,n){
            printf("%d",a[i]);
            if (i<n) printf("->");
        }
    }else{
        if (count(a+1,a+n,0)==1){
            printf("NO");
            return;
        }
        printf("YES\n");
        int st=n-2;
        while (a[st]) st--;
        FOR(i,1,n) {
            printf("%d",a[i]);
            if (i==n-1&&st>1) printf(")");
            if (i==n-1) printf(")");
            if (i<n) printf("->");
            if (i==st) printf("(");
            if (i==st-1) printf("(");
        }
    }
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    solve();
}