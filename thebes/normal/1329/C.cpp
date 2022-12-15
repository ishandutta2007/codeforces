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

const int MN = 4e6+6;
int t, n, m, h, g, i, j, arr[MN], arr2[MN], dep[MN], dep2[MN]; ll ans;
vi sna, op;

void init(int i){
    if(arr[2*i]==0&&arr[2*i+1]==0)
        dep[i]=dep2[i]=1;
    else{
        init(2*i); init(2*i+1);
        dep[i]=dep2[i]=dep[2*i]+1;
    }
}

void pop(int i){
    op.pb(i);
    if(arr[2*i]==0&&arr[2*i+1]==0)
        arr[i]=0, dep[i]=0;
    else{
        if(arr[2*i]>arr[2*i+1]){
            arr[i]=arr[2*i];
            pop(2*i);
        }
        else{
            arr[i]=arr[2*i+1];
            pop(2*i+1);
        }
        if(arr[2*i]&&arr[2*i+1]){
            dep[i]=min(dep[2*i],dep[2*i+1])+1;
        }
        else dep[i]=1;
    }
}

void go(int x,int dd){
    if(x>n) return;
    while(1){
        op.clear();
        pop(x);
        if(dep[x]+dd<g){
            for(auto v : op){
                arr[v]=arr2[v];
                dep[v]=dep2[v];
            }
            break;
        }
        else{
            for(auto v : op){
                arr2[v]=arr[v];
                dep2[v]=dep[v];
            }
            sna.pb(x);
        }
    }
    if(arr[2*x]) go(2*x,dd+1);
    if(arr[2*x+1]) go(2*x+1,dd+1);
}

int main(){
    for(scanf("%d",&t);t;t--){
        scanf("%d%d",&h,&g);
        n=(1<<h)-1; m=(1<<g)-1;
        for(i=1;i<=2*n+1;i++){
            arr[i]=arr2[i]=dep[i]=dep2[i]=0;
        }
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]),arr2[i]=arr[i];
        init(1);
        ans=0; sna.clear(); go(1,0);
        for(i=1;i<=m;i++){
            ans+=arr[i];
        }
        printf("%lld\n",ans);
        for(auto v : sna) printf("%d ",v);
        printf("\n");
    }
    return 0;
}