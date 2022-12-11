#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
    int n,m;
    cin>>n>>m;
    if (m>n) {
        printf("-1");
        return 0;
    }
    if (m==1){
        if (n==1) printf("a");
        else printf("-1");
        return 0;
    }
    for(int i=0;i<n-m+2;i++) printf("%c",'a'+i%2);
    REP(i,0,m-2) printf("%c",'c'+i);
}