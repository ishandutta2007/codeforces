#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const int inf=2e9;
const int MOD=1e9+7;
const int N=6e5+5,M=3e5+5,K=1e4+7;

map<lli,int> ma[N];
int n,m;
ll p[N],f[N],p1[N],f1[N];
string s[M],s1;
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) {
        cin>>s[i];
        int m1=s[i].length();
        ll v0=0;int v1=0;
        REP(j,0,m1){
            v0=M*v0+s[i][j]-'a';
            v1=K*v1+s[i][j]-'a';
            //v1+=s[j]-'a';
        }
        ma[m1][lli(v0,v1)]=i;
        //printf("%lld %d\n",v0,v1);
    }
    p[0]=p1[0]=1;
    FOR(i,1,N-5) {
        //p[i]=p[i-1]*M;
        p[i]=p[i-1]*K;
        p1[i]=p1[i-1]*M;
    }
    while (m--){
        cin>>s1;
        int m1=s1.length();
        f[m1]=f1[m1]=0;
        FORD(i,m1-1,0){
            f[i]=f[i+1]+(s1[i]-'a')*p[m1-i-1];
            f1[i]=f1[i+1]+(s1[i]-'a')*p1[m1-i-1];
            //f1[i]=f[i+1]+(s[i]-'a');
        }
        ll c0=0;
        ll c1=0;
        bool ok=false;
        REP(i,0,m1) if (!ok){
            FOR(j,0,2) if (j!=s1[i]-'a'){
                //int r1=(c0*M+j)*p[m1-i-1]+f[i+1];
                ll r1=(c0*K+j)*p[m1-i-1]+f[i+1];
                ll r2=(c1*M+j)*p1[m1-i-1]+f1[i+1];
                //printf("%d %lld %d\n",j,r2,r1);
                int sel=ma[m1][lli(r2,r1)];
                if (sel){
                    int wr=0;
                    REP(i1,0,i) wr+=s[sel][i1]!=s1[i1];
                    REP(i1,i+1,m1) wr+=s[sel][i1]!=s1[i1];
                    wr+=(s[sel][i]-'a'!=j);
                    if (!wr) ok=true;
                }
            }
            c0=c0*K+s1[i]-'a';
            c1=c1*M+s1[i]-'a';
        }
        if (ok) printf("YES\n");else printf("NO\n");
    }
}