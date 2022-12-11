#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e3+10;

int m,t[N][15][15],ans[N];
string s;
int main(){
    cin>>s>>m;
    FOR(i,1,10) if (s[i-1]=='1') t[1][i][i]=-1;
    REP(k,1,m)
        FOR(i,0,10)
            FOR(i1,0,10) if (t[k][i][i1]){
                FOR(j,i+1,10) if (s[j-1]=='1'&&j!=i1)
                    t[k+1][j-i][j]=i1;
//                printf("%d %d %d\n",k,i,i1);
            }
    int cw=-1,lu=-1;
    FOR(i,0,10)
        FOR(j,1,10) if (t[m][i][j]) cw=i,lu=j;
    if (cw==-1) printf("NO");
    else{
        printf("YES\n");
        FORD(i,m,1) {
            ans[i]=lu;
            int tcw=cw,tlu=lu;
            lu=t[i][tcw][tlu];cw=tlu-cw;
        }
        FOR(i,1,m) printf("%d ",ans[i]);
    }
}