#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}

}

using namespace debug;

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
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const int MN = 1e5+5, MM = 1003;
int n, m, sz, i, j, f[MM], pre[MN], suf[MN], fnd, ans;
string r, s, t;

int main(){
    cin >> s; n = s.size();
    r = s; reverse(r.begin(),r.end());
    s.insert(s.begin(),' ');
    r.insert(r.begin(),' ');
    for(scanf("%d",&m);m;m--){
        cin >> t; sz = t.size();
        t.insert(t.begin(),' ');
        memset(f,0,sizeof(f));
        f[1] = 1;
        for(i=2,j=1;i<sz;i++){
            if(t[i]==t[j]) f[i]=++j;
            else{
                while(j>1&&t[i]!=t[j]) j=f[j-1];
                if(t[i]==t[j]) j++;
                f[i]=j;
            }
        }
        fnd = 0;
        memset(suf,0,sizeof(suf));
        memset(pre,0,sizeof(pre));
        for(i=1,j=1;i<=n;i++){
            if(t[j]==s[i]){
                j++;
                if(j==sz+1){
                    fnd = 1;
                    break;
                }
                pre[i]=j-1;
            }
            else{
                while(j>1&&s[i]!=t[j]) j=f[j-1];
                if(s[i]==t[j]) j++;
                pre[i]=j-1;
            }
        }
        t.erase(t.begin());
        reverse(t.begin(),t.end());
        t.insert(t.begin(),' ');
        f[1] = 1;
        for(i=2,j=1;i<sz;i++){
            if(t[i]==t[j]) f[i]=++j;
            else{
                while(j>1&&t[i]!=t[j]) j=f[j-1];
                if(t[i]==t[j]) j++;
                f[i]=j;
            }
        }
        for(i=1,j=1;i<=n;i++){
            if(t[j]==r[i]){
                j++;
                if(j==sz+1){
                    fnd = 1;
                    break;
                }
                suf[n-i+1]=j-1;
            }
            else{
                while(j>1&&r[i]!=t[j]) j=f[j-1];
                if(r[i]==t[j]) j++;
                suf[n-i+1]=j-1;
            }
        }
        if(sz>1){
            int mx = 0;
            for(i=n;i>=1;i--){
                mx = max(mx, suf[i+1]);
                if(pre[i]+mx>=sz)
                    fnd=1;
            }
            if(fnd) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}