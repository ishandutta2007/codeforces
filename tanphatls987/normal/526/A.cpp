#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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

int n;
string s;
int main(){
    cin>>n>>s;
    FORD(i,n-1,0) if (s[i]=='*')
        FOR(j,1,i){
            bool ok=true;
            FOR(k,1,4) if (i-k*j>=0&&s[i-k*j]=='*');
            else ok=false;
            if (ok){
                printf("yes");
                return 0;
            }
        }
    printf("no");
}