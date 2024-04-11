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
const int M=1e2+5,N=2605;

int f[M][N];
string s;
void prepare(){
    f[0][0]=1;
    REP(phase,1,M)
        for(int i=phase,sum=0;i<N;i++){
            sum=(sum+f[phase-1][i-1])%MOD;
            f[phase][i]=sum;
            if (i>=26) sum=(sum+MOD-f[phase-1][i-26])%MOD;
        }
}
int main(){
    prepare();
    int test;
    cin>>test;
    while (test--){
        cin>>s;
        int n=0,m=s.length();
        for(auto i:s) n+=i-'a'+1;
        printf("%d\n",(f[m][n]+MOD-1)%MOD);
    }
}