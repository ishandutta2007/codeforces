#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7,BASE[2]={31,37};
const int N=3e3+10;

string s,sd;
int n,m;
ll pb[2][N],ha[2][N][2],cur[2];
ll calhash(int L,int R,int dir,int type){
    int len=R-L+1;
    if (!dir) return (ha[0][R][type]-ha[0][L-1][type]*pb[type][len]%MOD+MOD)%MOD;
    return (ha[1][L][type]-ha[1][R+1][type]*pb[type][len]%MOD+MOD)%MOD;
}
void prepare(){
    cin>>s>>sd;
    n=s.length(),m=sd.length();
    FOR(i,1,n)
        FOR(type,0,1) ha[0][i][type]=(ha[0][i-1][type]*BASE[type]+s[i-1]-'a')%MOD;
    FORD(i,n,1)
        FOR(type,0,1) ha[1][i][type]=(ha[1][i+1][type]*BASE[type]+s[i-1]-'a')%MOD;
    pb[0][0]=pb[1][0]=1;
    FOR(i,1,n)
        FOR(type,0,1) pb[type][i]=pb[type][i-1]*BASE[type]%MOD;
}
ii check(int len){
    FOR(st,1,n-len+1){
        bool ok=1;
        FOR(type,0,1) ok&=(calhash(st,st+len-1,0,type)==cur[type]);
        if (ok) return ii(st,st+len-1);
    }
    FORD(st,n,len){
        bool ok=1;
        FOR(type,0,1) ok&=(calhash(st-len+1,st,1,type)==cur[type]);
        if (ok) return ii(st,st-len+1);
    }
    return ii(-1,-1);
}
void solve(){
//    cout<<pb[1][1]<<'\n';
    vector <ii> ans;
    int clen=0;
    ii last=ii(-1,-1);
    for(auto ch:sd){
        clen++;
        FOR(type,0,1) cur[type]=(cur[type]*BASE[type]+ch-'a')%MOD;
        ii nx=check(clen);
        if (nx.X==-1){
            if (last.X==-1){
                printf("-1");
                return;
            }
            ans.push_back(last);
            clen=1;
            FOR(type,0,1) cur[type]=ch-'a';
            nx=check(clen);
        }
        last=nx;
//        cout<<clen<<" "<<cur[0]<<" "<<cur[1]<<" "<<last.X<<" "<<last.Y<<'\n';
    }
    ans.push_back(last);
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d %d\n",i.X,i.Y);
}
int main(){
    prepare();
    solve();
}