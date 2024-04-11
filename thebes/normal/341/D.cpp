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

const int MN = 1005, MM = 1e5+5;
int N, M, S, i, x, y, a, b, ans[MM], cnt, tot; ll v;
struct event{int x, y, id; ll v;}evt[4*MM],tmp[4*MM];
ll odd_bit[2][MN], even_bit[2][MN];

inline void upd(ll p,ll v,ll *bit){for(;p&&p<=N;p+=p&-p)bit[p]^=v;}
inline ll qu(ll p,ll *bit){ll r=0;for(;p;p-=p&-p)r^=bit[p];return r;}

void solve(int l,int r){
    if(l!=r){
        int mid = (l+r)>>1, i, j;
        solve(l, mid);
        solve(mid+1, r);
        int sz = 0;
        for(i=l,j=mid+1;i<=mid;i++){
            while(j<=r&&evt[j].x<evt[i].x){
                if(~evt[j].id){
                    int idx = (evt[j].y&1), qidx = ((evt[j].y+1)>>1);
                    if(evt[j].x&1) ans[evt[j].id] ^= qu(qidx,odd_bit[idx]);
                    else ans[evt[j].id] ^= qu(qidx,even_bit[idx]);
                }
                tmp[sz++]=evt[j++];
            }
            if(evt[i].id==-1){
                int idx = (evt[i].y&1), uidx = ((evt[i].y+1)>>1);
                if(evt[i].x&1) upd(uidx,evt[i].v,odd_bit[idx]);
                else upd(uidx,evt[i].v,even_bit[idx]);
            }
            tmp[sz++]=evt[i];
        }
        while(j<=r){
            if(~evt[j].id){
                int idx = (evt[j].y&1), qidx = ((evt[j].y+1)>>1);
                if(evt[j].x&1) ans[evt[j].id] ^= qu(qidx,odd_bit[idx]);
                else ans[evt[j].id] ^= qu(qidx,even_bit[idx]);
            }
            tmp[sz++]=evt[j++];
        }
        for(i=l;i<=mid;i++){
            if(evt[i].id==-1){
                int idx = (evt[i].y&1), uidx = ((evt[i].y+1)>>1);
                if(evt[i].x&1) upd(uidx,evt[i].v,odd_bit[idx]);
                else upd(uidx,evt[i].v,even_bit[idx]);
            }
        }
        for(i=0;i<sz;i++)
            evt[l+i]=tmp[i];
    }
}

int main(){
    scanf("%d%d",&N,&M);
    for(;M;M--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d%d%d%d",&x,&y,&a,&b);
            evt[tot++]={a,b,++cnt,0};
            if(x-1>=1) evt[tot++]={x-1,b,cnt,0};
            if(y-1>=1) evt[tot++]={a,y-1,cnt,0};
            if(x-1>=1&&y-1>=1) evt[tot++]={x-1,y-1,cnt,0};
        }
        else{
            scanf("%d%d%d%d%d",&x,&y,&a,&b,&v);
            evt[tot++]={x,y,-1,v};
            if(b+1<=N) evt[tot++]={x,b+1,-1,v};
            if(a+1<=N) evt[tot++]={a+1,y,-1,v};
            if(a+1<=N&&b+1<=N) evt[tot++]={a+1,b+1,-1,v};
        }
    }
    solve(0,tot-1);
    for(i=1;i<=cnt;i++)
        printf("%d\n",ans[i]);
    return 0;
}