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

const int MN = 3005;
int n, k, arr[MN], i, x;
queue<int> q; string s; vi ans;
vector<vi> sna;

void go(){
    int sz=q.size(); sna.pb(vi());
    while(sz--){
        x=q.front(); q.pop();
        swap(arr[x],arr[x+1]);
        ans.pb(x); sna.back().pb(x);
        if(x+2<=n&&arr[x+2]==0) q.push(x+1);
        if(x-1>=1&&arr[x-1]==1) q.push(x-1);
    }
    if(q.size()) go();
}

int main(){
    cin >> n >> k >> s;
    for(i=1;i<=n;i++){
        arr[i]=s[i-1]=='R';
    }
    for(i=1;i<n;i++){
        if(arr[i]==1&&arr[i+1]==0) q.push(i);
    }
    go();
    if(sna.size()<=k&&k<=ans.size()){
        int idx=sna.size()-1, cnt=0, t=0, rem=ans.size();
        for(auto w : sna){
            if(t+rem==k) break;
            t++;
            vi acc;
            for(auto v : w){
                acc.pb(v);
                rem--; cnt++;
                if(t+rem==k) break;
            }
            printf("%d ",acc.size());
            for(auto v : acc) printf("%d ",v);
            printf("\n");
            if(t+rem==k) break;
        }
        for(i=cnt;i<ans.size();i++){
            printf("1 %d\n",ans[i]);
        }
    }
    else printf("-1\n");
    return 0;
}