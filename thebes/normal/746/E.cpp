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

const int MN = 2e5+5;
int n, m, i, j, x, arr[MN], cnt, c[2], b[2], rep[MN], ord[MN];
set<int> st; queue<int> go[2];

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        c[arr[i]&1]++;
        b[arr[i]&1]++;
        if(st.count(arr[i])) c[arr[i]&1]--;
        else st.insert(arr[i]);
        ord[i] = i;
    }
    sort(ord+1,ord+n+1,[](int i,int j){return arr[i]>arr[j];});
    for(i=2;i<=m&&c[0]<n/2;i+=2){
        if(!st.count(i)){
            go[0].push(i);
            c[0] ++;
        }
    }
    for(i=1;i<=m&&c[1]<n/2;i+=2){
        if(!st.count(i)){
            go[1].push(i);
            c[1] ++;
        }
    }
    if(c[0]<n/2||c[1]<n/2) printf("-1\n");
    else{
        c[0] = c[1] = 0;
        st.clear();
        for(i=1;i<=n;i++){
            x = ord[i];
            if(st.count(arr[x])){
                int par = arr[x]%2;
                if(b[par]>b[!par]){
                    cnt ++;
                    b[par]--, b[!par]++;
                    arr[x]=go[!par].front();
                    go[!par].pop();
                }
                else{
                    cnt ++;
                    arr[x]=go[par].front();
                    go[par].pop();
                }
            }
            st.insert(arr[x]);
        }
        for(i=1;i<=n;i++){
            x = ord[i];
            int par = arr[x]%2;
            c[par]++;
            if(c[par]>n/2){               
                c[par]--;
                cnt++;
                arr[x]=go[!par].front();
                go[!par].pop();
                c[!par]++;
            }
        }
        printf("%d\n",cnt);
        for(i=1;i<=n;i++) printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}