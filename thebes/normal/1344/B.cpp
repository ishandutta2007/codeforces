#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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
#define F first
#define S second

const int MN = 1005;
int n, m, i, j, dx[]={-1,1,0,0}, dy[]={0,0,-1,1}, r[MN], c[MN], fl, rr[MN], cc[MN], ans;
string s[MN]; bitset<MN> vs[MN];
set<int> rpos[MN], cpos[MN];

void go(int x,int y){
    vs[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x, ny=dy[i]+y;
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(!vs[nx][ny]&&s[nx][ny]=='#') go(nx,ny);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        cin >> s[i];
        s[i].insert(s[i].begin(),' ');
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(s[i][j]=='#'){
                r[i]=1;
                rpos[i].insert(j);
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s[j][i]=='#'){
                c[i]=1;
                cpos[i].insert(j);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(s[i][j]=='.'){
                auto bef = rpos[i].lower_bound(j);
                auto aft = rpos[i].upper_bound(j);
                if(rpos[i].size()>=2&&bef!=rpos[i].begin()&&aft!=rpos[i].end()) fl=1;
                bef = cpos[j].lower_bound(i);
                aft = cpos[j].upper_bound(i);
                if(cpos[j].size()>=2&&bef!=cpos[j].begin()&&aft!=cpos[j].end()) fl=1;
                if(!r[i]&&!c[j]) rr[i]=cc[j]=1;
            }
            else rr[i]=cc[j]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(!rr[i]) fl=1;
    }
    for(i=1;i<=m;i++){
        if(!cc[i]) fl=1;
    }
    if(fl) printf("-1\n");
    else{
        ans = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(!vs[i][j]&&s[i][j]=='#'){
                    ans ++;
                    go(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}