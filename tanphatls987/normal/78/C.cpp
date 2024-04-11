#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","r",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

int n,m,k;
int main(){
    cin>>n>>m>>k;
    if (n%2){
        bool ok=false;
        FOR(i,2,sqrt(m)) if (m%i==0&&m/i>=k) {ok=true;break;}
        if (k==1&&m>1) ok=true;
        if (ok) printf("Timur");else printf("Marsel");
    }else printf("Marsel");
}