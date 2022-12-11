#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int main(){
    int hh,mm,x;
    scanf("%d:%d%d",&hh,&mm,&x);
    if (mm+x>=60){
        hh=(hh+1)%24;
        x-=60-mm;
        mm=0;
    }
    hh=(hh+x/60)%24;
    mm+=x%60;
    printf("%02d:%02d",hh,mm);
}