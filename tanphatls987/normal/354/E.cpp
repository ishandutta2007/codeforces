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
const int N=20;

int t[N][5],test;
ll ans[6];
string s;
queue <ii> q;
int main(){
    cin>>test;
    while (test--){
        cin>>s;
        int n=s.length();
        memset(t,0,sizeof(t));
        t[n][0]=-1;
        q.push(ii(n,0));
        while (!q.empty()){
            int cpos=q.front().X,cnum=q.front().Y;
            //printf("%d %d\n",cpos,cnum);
            q.pop();
            FOR(n7,0,6)
                FOR(n4,0,6-n7){
                    int nnum=cnum+n7*7+n4*4;
                    if (nnum%10!=(s[cpos-1]-'0')) continue;
                    if (!t[cpos-1][nnum/10]){
                        t[cpos-1][nnum/10]=cnum+1;
                        if (cpos>1) q.push(ii(cpos-1,nnum/10));
                    }
                }
        }
        if (!t[0][0]) printf("-1\n");
        else {
            memset(ans,0,sizeof(ans));
            for(int i=0,cmem=0,ct=t[0][0]-1;i<n;ct=t[++i][ct]-1){
                int cnum=cmem*10+s[i]-'0'-ct;
                FOR(n7,0,6)
                    FOR(n4,0,6-n7) if (n7*7+n4*4==cnum){
                        REP(j,0,n7) ans[j]=ans[j]*10+7;
                        REP(j,n7,n7+n4) ans[j]=ans[j]*10+4;
                        REP(j,n7+n4,6) ans[j]*=10;
                    }
                cmem=ct;
            }
            REP(i,0,6) printf("%I64d ",ans[i]);
            ENDL;
        }
    }
}