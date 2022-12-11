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

const int inf=1e9+10;
const int MOD=1e9+7;
const int N=24;


int main(){
    printf("302\n0 500000\n");
    int pos=24195;
    FORD(i,300,1){
        printf("%d %d\n",pos+i,i);
        pos+=2*i;
    }
    printf("500000 500000");
}