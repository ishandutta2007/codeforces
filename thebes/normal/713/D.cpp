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

const int MN = 1005, LG = 11;
int n, m, q, i, j, k, l, arr[MN][MN], x, y, a, b, lo, hi, mid, bit[MN];
short sp[MN][MN][LG][LG];

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=1;i<MN;i++){
        for(j=LG-1;j>=0;j--){
            if((1<<j)&i){
                bit[i]=j;
                break;
            }
        }
    }
    for(i=n;i>=1;i--){
        for(j=m;j>=1;j--){
            if(arr[i][j]){
                arr[i][j]+=min(arr[i+1][j],min(arr[i+1][j+1],arr[i][j+1]));
            }
            sp[i][j][0][0]=arr[i][j];
        }
    }
    for(k=0;k<LG;k++){
        for(l=0;l<LG;l++){
            if(!k&&!l) continue;
            for(i=1;i<=n-(1<<k)+1;i++){
                for(j=1;j<=m-(1<<l)+1;j++){
                    if(k&&l) sp[i][j][k][l]=max(max(sp[i][j][k-1][l-1],sp[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]),max(sp[i+(1<<(k-1))][j][k-1][l-1],sp[i][j+(1<<(l-1))][k-1][l-1]));
                    else if(k) sp[i][j][k][l]=max(sp[i][j][k-1][l],sp[i+(1<<(k-1))][j][k-1][l]);
                    else sp[i][j][k][l]=max(sp[i][j][k][l-1],sp[i][j+(1<<(l-1))][k][l-1]);
                }
            }
        }
    }
    for(scanf("%d",&q);q;q--){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        int dx=a-x+1, dy=b-y+1;
        int px, py, lx, ly, res;
        lo=1,hi=min(dx,dy)+1;
        while(lo<hi){
            mid=(lo+hi)>>1;
            px=bit[dx-mid+1], py=bit[dy-mid+1];
            lx=dx-mid+1, ly=dy-mid+1;
            res=max(max(sp[x][y][px][py],sp[x+lx-(1<<px)][y+ly-(1<<py)][px][py]),max(sp[x+lx-(1<<px)][y][px][py],sp[x][y+ly-(1<<py)][px][py]));
            if(res>=mid) lo=mid+1;
            else hi=mid;
        }
        printf("%d\n",lo-1);
    }
    return 0;
}