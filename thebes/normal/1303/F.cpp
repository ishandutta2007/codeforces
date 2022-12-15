#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 303, MM = 2e6+6;
int n, m, q, i, j, x, y, w, dx[]={-1,1,0,0}, dy[]={0,0,-1,1}, arr[MN][MN], lst[MN][MN], dn[MM], ans[MM], ds[MN*MN];
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
struct _{int x, y, t;};
vector<_> a[MM], b[MM];

int main(){
    scanf("%d%d%d",&n,&m,&q);
    int lim = 0;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) lst[i][j]=1;
    for(i=1;i<=q;i++){
        scanf("%d%d%d",&x,&y,&w);
        lim = max(lim, w);
        if(i!=1){
            a[arr[x][y]].pb({x,y,lst[x][y]});
            b[arr[x][y]].pb({x,y,i-1});
            dn[arr[x][y]]=max(dn[arr[x][y]],lst[x][y]);
        }
        lst[x][y] = i;
        arr[x][y] = w;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            a[arr[i][j]].pb({i,j,lst[i][j]});
            b[arr[i][j]].pb({i,j,q});
            dn[arr[i][j]]=max(dn[arr[i][j]],lst[i][j]);
        }
    }
    for(j=0;j<=lim;j++){
        if(a[j].empty()) continue;
        sort(a[j].begin(),a[j].end(),[](_ i,_ j){return i.t<j.t;});
        sort(b[j].begin(),b[j].end(),[](_ i,_ j){return i.t>j.t;});
        int ct = 1, cur = 0;
        for(i=1;i<=n;i++){
            for(int k=1;k<=m;k++){
                ds[(i-1)*m+k]=(i-1)*m+k;
                arr[i][k]=0;
            }
        }
        for(auto v : a[j]){
            ans[ct]+=cur;
            ans[min(v.t-1,dn[j])+1]-=cur;
            ct=min(v.t-1,dn[j])+1;
            if(arr[v.x][v.y]) continue;
            cur ++;
            int id = (v.x-1)*m+v.y;
            arr[v.x][v.y]=1;
            for(i=0;i<4;i++){
                int nx=v.x+dx[i],ny=v.y+dy[i];
                if(!arr[nx][ny]) continue;
                int ot = (nx-1)*m+ny;
                if(fnd(id)!=fnd(ot)) ds[fnd(id)]=fnd(ot),cur--;
            }
        }
        ans[ct]+=cur;
        ans[dn[j]+1]-=cur;
        for(i=1;i<=n;i++){
            for(int k=1;k<=m;k++){
                ds[(i-1)*m+k]=(i-1)*m+k;
                arr[i][k]=0;
            }
        }
        ct = q, cur = 0;
        for(auto v : b[j]){
            ans[ct+1]-=cur;
            ans[max(v.t,dn[j])+1]+=cur;
            ct=max(v.t,dn[j]);
            if(arr[v.x][v.y]) continue;
            cur ++;
            int id = (v.x-1)*m+v.y;
            arr[v.x][v.y]=1;
            for(i=0;i<4;i++){
                int nx=v.x+dx[i],ny=v.y+dy[i];
                if(!arr[nx][ny]) continue;
                int ot = (nx-1)*m+ny;
                if(fnd(id)!=fnd(ot)) ds[fnd(id)]=fnd(ot),cur--;
            }
        }
        ans[ct+1]-=cur;
        ans[dn[j]+1]+=cur;
    }
    for(i=1;i<=q;i++) ans[i]+=ans[i-1],printf("%d\n",ans[i]);
    return 0;
}