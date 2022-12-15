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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const ll MN = 4e5+5, LG = 20;
ll Q, cnt=1, w[MN], anc[MN][LG], mx[MN][LG], dep[MN], res, last, x, y, i, p;
pll ans[MN][LG];

int main(){
    for(i=0;i<LG;i++) ans[1][i]={-1,0};
    for(scanf("%lld",&Q);Q;Q--){
        scanf("%lld%lld%lld",&i,&x,&y);
        x ^= last, y ^= last;
        if(i==1){
            dep[++cnt]=dep[x]+1;
            anc[cnt][0]=x;
            mx[cnt][0]=w[x];
            w[cnt]=y;
            for(int j=1;j<LG;j++){
                mx[cnt][j]=max(mx[cnt][j-1],mx[anc[cnt][j-1]][j-1]);
                anc[cnt][j]=anc[anc[cnt][j-1]][j-1];
            }
            p=cnt;
            for(int j=LG-1;j>=0;j--){
                if((1<<j)<=dep[p]&&mx[p][j]<w[cnt]){
                    p = anc[p][j];
                }
            }
            p = anc[p][0];
            if(w[p]<w[cnt]) p=-1;
            ans[cnt][0]={p,w[cnt]};
            for(int j=1;j<LG;j++){
                if(ans[cnt][j-1].first==-1){
                    ans[cnt][j].first=-1;
                    continue;
                }
                ans[cnt][j].first=ans[ans[cnt][j-1].first][j-1].first;
                ans[cnt][j].second=ans[cnt][j-1].second+ans[ans[cnt][j-1].first][j-1].second;
            }
        }
        else{
            res = 0;
            for(i=LG-1;i>=0;i--){
                if(ans[x][i].first!=-1&&ans[x][i].second<=y){
                    res += (1<<i);
                    y -= ans[x][i].second;
                    x = ans[x][i].first;
                }
            }
            if(y>=ans[x][0].second) res++;
            printf("%lld\n",res);
            last = res;
        }
    }
    return 0;
}