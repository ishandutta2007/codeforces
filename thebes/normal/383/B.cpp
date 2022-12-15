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

const int MN = 1e5+5;
int N, M, i, j, x, y;
pii arr[MN]; set<pii> st;
inline int diag(pii i){return i.F+i.S;}

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++)
        scanf("%d%d",&arr[i].F,&arr[i].S);
    sort(arr+1,arr+M+1,[](pii i,pii j){return diag(i)<diag(j);});
    int pre = 0;
    for(i=1;i<=M;i=j){
        if(st.size()){
            int dd = diag(arr[i])-pre;
            set<pii> res;
            for(auto it : st){
                pii re(it.F,it.S);
                if(it.S==pre-1) re.S=diag(arr[i])-1;
                if(it.F!=1) re.F+=dd;
                if(re.F<=re.S) res.insert(re);
            }
            st=res;
        }
        for(j=i;j<=M&&diag(arr[i])==diag(arr[j]);j++){
            if(st.empty()){
                st.insert({arr[j].F,arr[j].F});
                continue;
            }
            auto it=st.upper_bound({arr[j].F,1<<30});
            if(it!=st.begin()){
                auto it2=it; it2--;
                if(it2->S>=arr[j].F) continue;
                pii seg(arr[j].F,arr[j].F);
                if(it2->S==seg.F-1){
                    seg.F=min(seg.F,it2->F);
                    st.erase(it2);
                }
                if(it!=st.end()&&it->F==seg.S+1){
                    seg.S=max(seg.S,it->S);
                    st.erase(it);
                }
                st.insert(seg);
            }
            else{
                pii seg(arr[j].F,arr[j].F);
                if(it->F==seg.S+1){
                    seg.S=max(seg.S,it->S);
                    st.erase(it);
                }
                st.insert(seg);
            }
        }
        pre = diag(arr[i]);
    }
    if(st.size()){
        int dd = 2*N-pre;
        set<pii> res;
        for(auto it : st){
            pii re(it.F,it.S);
            if(it.S==pre-1) re.S=2*N-1;
            if(it.F!=1) re.F+=dd;
            if(re.F<=re.S) res.insert(re);
        }
        st=res;
    }
    if(st.size()){
        auto it=st.upper_bound({N,1<<30});
        if(it!=st.begin()){
            it--;
            if(it->S>=N){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n",2*N-2);
    return 0;
}