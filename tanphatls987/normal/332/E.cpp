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
const ll BASE[2]={97,67};
const int N=2e3+10,M=2e2+10;

string s1,s2,ans;
int n,m,k,t[N][M];
ii g[N][2];
void prepare(){
    getline(cin,s1);
    getline(cin,s2);
    cin>>k;
    n=s1.length(),m=s2.length();
//    cout<<s1<<'\n'<<s2<<'\n'<<k<<'\n';
}
ii calhash(int cur,int len,int type){
    int ans=0,c=0;
    for(int j=cur;j<m;j+=len) ans=(BASE[type]*ans+s2[j]-32)%MOD,c++;
    return ii(ans,c);
}
bool operator ==(ii a,ii b){
    return (a.X==b.X&&a.Y==b.Y);
}
string solve(){
    int k1=min(k,n);
    FOR(i,1,k1) ans.push_back('2');
    REP(i,0,k1)
        for(int j=i;j<n;j+=k1)
            FOR(j1,0,1){
                g[i][j1].X=(BASE[j1]*g[i][j1].X+s1[j]-32)%MOD;
                g[i][j1].Y++;
            }
    FOR(use,1,m){
        memset(t[k1],0,sizeof(t[k1]));
        t[k1][use]=-1;
        FORD(i,k1,1){
            FOR(j,0,use) t[i-1][j]=(t[i][j]?1:0);
            REP(j,0,use) if (!t[i-1][j]&&t[i][j+1]){
                ii x[2]={calhash(j,use,0),calhash(j,use,1)};
                if (x[0]==g[i-1][0]&&x[1]==g[i-1][1]) t[i-1][j]=2;
            }
        }
//        REP(i,0,k1)
//            FOR(j,0,use) cout<<t[i][j]<<" \n"[j==use];
        if (t[0][0]){
            int cur=0;
            bool sma=0;
            REP(i,0,k1){
                int x=t[i][cur]-1;
                if (!sma&&x>ans[i]-'0') break;
                sma|=(x<ans[i]-'0');
                ans[i]='0'+x;
                cur+=x;
            }
        }
    }
    if (ans[0]=='2') return "0";
    FOR(i,k1+1,k) ans.push_back('0');
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}