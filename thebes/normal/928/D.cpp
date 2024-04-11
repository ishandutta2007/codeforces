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

const int MN = 3e5+5;
int ans, i, j, p, nxt, id[MN], t[MN][26], ed[MN], sz;
string s, ss, res[MN];

int main(){
    while(getline(cin,s)){
        ans += s.size()+1;
        for(i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                ss.clear();
                for(j=i;j<s.size()&&s[j]>='a'&&s[j]<='z';j++) ss.pb(s[j]);
                i=j; p = 0; int cnt=0;
                for(char c : ss){
                    cnt++;
                    if(!t[p][c-'a']) t[p][c-'a']=++nxt;
                    p=t[p][c-'a'];
                    if(id[p]>0){
                        int f=0;
                        for(int k=0;k<min(res[id[p]].size(),ss.size());k++){
                            if(res[id[p]][k]!=ss[k]) f=1;
                        }
                        if(ss.size()>=res[id[p]].size()&&!f) cnt=min(ss.size(),cnt+1+ss.size()-res[id[p]].size());
                        else cnt = ss.size();
                        break;
                    }
                }
                p = 0;
                for(char c : ss){
                    if(!t[p][c-'a']) t[p][c-'a']=++nxt;
                    p=t[p][c-'a'];
                }
                res[++sz]=ss;
                if(!ed[p]){
                    ed[p]=1; p=0;
                    for(char c : ss){
                        p=t[p][c-'a'];
                        if(!id[p]) id[p]=sz;
                        else id[p]=-1;
                    }
                }
                ans -= ss.size()-cnt;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}