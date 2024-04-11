#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=1e2+10;

int h[2][N]={0},n,m,r[2][N]={0},t;
string s[2];
char team,sign;
int main(){
    cin>>s[0]>>s[1]>>n;
    while (n--){
        cin>>t>>team>>m>>sign;
        int d=team!='h';
        h[d][m]+=((sign=='y')?1:2);
        if (h[d][m]>=2&&r[d][m]==0)
            cout<<s[d]<<" "<<m<<" "<<t<<'\n',r[d][m]=1;
    }
}