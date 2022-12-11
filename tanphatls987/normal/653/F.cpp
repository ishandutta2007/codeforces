#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
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
const int N=5e5+10;

int n;
string s;
int sa[N],lcp[N],pos[N];
int key[N];
ii skey[N];
///
int goR[N][2];
///
int st[N],psum[N];
vector <int> v[N<<1];

bool operator ==(ii a,ii b){
    return a.X==b.X&&a.Y==b.Y;
}
bool comp(int x,int y){
    if (skey[x].X==skey[y].X) return skey[x].Y<skey[y].Y;
    return skey[x].X<skey[y].X;
}
void buildLCA(){
    REP(i,0,n) sa[i]=i;
    key[n-1]=0;
    REP(i,0,n-1) key[i]=s[i]=='('?1:2;
    REP(i,0,n) skey[i]=ii(key[i],0);
    sort(sa,sa+n,comp);
    for(int pha=0;key[sa[n-1]]<n-1;pha++){
        REP(i,0,n) skey[i]=ii(key[i],key[(i+(1<<pha))%n]);
        sort(sa,sa+n,comp);
        REP(i,1,n) key[sa[i]]=key[sa[i-1]]+(skey[sa[i]]!=skey[sa[i-1]]);
    }
}
void buildLCP(){
    REP(i,0,n) pos[sa[i]]=i;
    for(int i=0,j=0;i<n-1;i++,j=max(j-1,0)){
        int sel=sa[pos[i]-1];
        while (s[sel+j]==s[i+j]) j++;
        lcp[pos[i]]=j;
    }
    REP(i,0,n) goR[sa[i]][0]=sa[i]+lcp[i]+1;
}
void prepare(){
    cin>>n>>s;
    s=s+"@";
    n++;
    buildLCA();
//    REP(i,0,n) cout<<sa[i]<<" \n"[i==n-1];
    buildLCP();
//    REP(i,0,n) cout<<lcp[i]<<" \n"[i==n-1];
    ///find max right i
    n--;
    FOR(i,1,n) psum[i]=psum[i-1]+(s[i-1]=='('?1:-1);
    psum[n+1]=-inf;
    int top=0;
    st[0]=n+1;
    FORD(i,n,0){
        while (psum[i]<=psum[st[top]]) top--;
        goR[i][1]=st[top]-1;
        st[++top]=i;
     }
//    FOR(i,0,n) cout<<goR[i][0]<<" "<<goR[i][1]<<'\n';
}
ll solve(){
    ll ans=0;
    FOR(i,0,n) v[psum[i]+N].push_back(i);
    REP(i,0,n){
        int L=goR[i][0],R=goR[i][1];
        if (L>R) continue;
        int idx=psum[i]+N;
        ans+=upper_bound(v[idx].begin(),v[idx].end(),R)-lower_bound(v[idx].begin(),v[idx].end(),L);
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}