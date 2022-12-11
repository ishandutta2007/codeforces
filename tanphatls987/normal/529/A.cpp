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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

string s;
int f[N],Skey[N],key[N],bw[N],fw[N],sa[N],a[N],n;
vector <int> q[N];
int comp(int p1,int p2,int bar){
    if (Skey[p1]==Skey[p2]) return Skey[(p1+bar)%n]!=Skey[(p2+bar)%n];
    return Skey[p1]!=Skey[p2];
}
void prepare(){
    REP(i,0,n) a[i]=(s[i]==')');
    REP(i,0,n) q[a[i]].push_back(i);
    int top=0;
    FOR(i,0,1) while (!q[i].empty()) sa[top++]=q[i].back(),q[i].pop_back();
    key[sa[0]]=0;
    REP(i,1,n) key[sa[i]]=key[sa[i-1]]+a[sa[i]]!=a[sa[i-1]];
    int m=int(ceil(log2(n)));
    //printf("%d %d\n",n,m);
    FOR(bar,1,m){
        //REP(i,0,n) cout<<sa[i]<<" \n"[i==n-1];
        top=key[sa[n-1]];
        REP(i,0,n) Skey[i]=key[i];
        FORD(i,n-1,0){
            int pos=(sa[i]-(1<<(bar-1))+n)%n;
            q[key[pos]].push_back(pos);
        }
        int tmp=0;
        FOR(i,0,top) while (!q[i].empty())
            sa[tmp++]=q[i].back(),q[i].pop_back();
        key[sa[0]]=0;
        REP(i,1,n) key[sa[i]]=key[sa[i-1]]+comp(sa[i],sa[i-1],1<<(bar-1));
    }
    //REP(i,0,n) cout<<sa[i]<<" \n"[i==n-1];
}
string solve(){
    string ans;
    int sum=0;
    REP(i,0,n) sum+=((a[i]>0)?1:-1);
    if (sum>=0){
        FOR(i,1,sum) ans.push_back('(');
        FORD(i,n,1) f[i]=f[i+1]+(a[i-1]?1:-1);
        bw[0]=fw[n+1]=n+1;
        FOR(i,1,n) bw[i]=min(bw[i-1],f[i]);
        FORD(i,n,1) fw[i]=min(fw[i+1],f[i]);
//        FOR(i,1,n) cout<<bw[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<fw[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
        REP(i,0,n) if (bw[sa[i]]-f[sa[i]+1]>=0&&fw[sa[i]+1]+f[1]-f[sa[i]+1]>=0){
            REP(j,sa[i],n) ans.push_back(s[j]);
            REP(j,0,sa[i]) ans.push_back(s[j]);
            break;
        }
    }else{
        FOR(i,1,n) f[i]=f[i-1]+(a[i-1]?1:-1);
        bw[0]=fw[n+1]=-n-1;
        FORD(i,n,1) fw[i]=max(fw[i+1],f[i]);
        FOR(i,1,n) bw[i]=max(bw[i-1],f[i]);
//        FOR(i,1,n) cout<<bw[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<fw[i]<<" \n"[i==n];
//        FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
        REP(i,0,n) if (fw[sa[i]+1]-f[sa[i]]<=0&&bw[sa[i]]+f[n]-f[sa[i]]<=0){
            REP(j,sa[i],n) ans.push_back(s[j]);
            REP(j,0,sa[i]) ans.push_back(s[j]);
            break;
        }
        FORD(i,-1,sum) ans.push_back(')');
    }
    return ans;
}
int main(){
    cin>>s;
    n=s.length();
    prepare();
//    REP(i,0,n) cout<<sa[i]<<" \n"[i==n-1];
    cout<<solve();
}