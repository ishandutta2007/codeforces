#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("628.inp","r",stdin)
#define OUTPUT freopen("628.out","w",stdout)
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
const int N=3e3+10;

int n,m,a[N][N],b[N][N],ra[N][N],la[N][N];
string st;
ii s[N];
void addy(int x,int y,int v){
    while (y){
        b[x][y]+=v;
        y-=y&-y;
    }
}
void add(int x,int y,int v){
    while (x){
        addy(x,y,v);
        x-=x&-x;
    }
}
int gety(int x,int y){
    int ans=0;
    while (y<N){
        ans+=b[x][y];
        y+=y&-y;
    }
    return ans;
}
int get(int x,int y){
    int ans=0;
    while (x<N){
        ans+=gety(x,y);
        x+=x&-x;
    }
    return ans;
}
void prepare(){
    cin>>n>>m;
    FOR(i,1,n) {
        cin>>st;
        FOR(j,1,m) a[i][j]=st[j-1]=='z';
    }
    FOR(i,1,n){
        FORD(j,m,1) ra[i][j]=a[i][j]?ra[i][j+1]+1:0;
        FOR(j,1,m) la[i][j]=a[i][j]?la[i][j-1]+1:0;
    }
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<ra[i][j]<<" \n"[j==m];
//    FOR(i,1,n)
//        FOR(j,1,m) cout<<la[i][j]<<" \n"[j==m];
}
bool check(int x,int y){
    return (x>0&&x<=n&&y>0&&y<=m);
}
int getlar(int xa,int ya){
//    cout<<"->"<<get(N-1,N-1)<<" "<<get(xa,N-1)<<" "<<get(N-1,ya)<<" "<<get(xa,ya)<<'\n';
    return get(n,m)-get(xa,m)-get(n,ya)+get(xa,ya);
}
int cal(int sx,int sy){
    int top=0;
    int ans=0;
    for(int x=sx,y=sy;check(x,y);x++,y--){
        if (a[x][y]){
            s[++top]=ii(x,min(x+la[x][y]-1,N-1));
            add(s[top].X,s[top].Y,1);
//            cout<<x<<" "<<y<<" "<<get(max(x-ra[x][y],0)<<" "<<x<<'\n';
//            cout<<s[top].X<<" "<<s[top].Y<<'\n';
            ans+=get(max(x-ra[x][y]+1,1),x);
            continue;
        }
        FOR(i,1,top) add(s[i].X,s[i].Y,-1);
        top=0;
    }
    FOR(i,1,top) add(s[i].X,s[i].Y,-1);
    return ans;
}
ll solve(){
    ll ans=0;
    FOR(st,1,m) ans+=cal(1,st);
    FOR(st,2,n) ans+=cal(st,m);
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}