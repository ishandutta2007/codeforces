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

const int MN = 505;
int a[MN][MN], dp[MN][MN], lnk[MN][MN], n, k, i, j, l, c;
string s; vector<string> vec;

void fix(int l,int r){
    if(l>=r) return;
    if(s[l-1]!=s[r-1]) s[l-1]=s[r-1];
    fix(l+1,r-1);
}

int main(){
    cin >> s >> k; n = s.size();
    fox(j,1,n){
        c = 0;
        for(i=1;j-i>=1&&j+i<=n;i++){
            if(s[j-i-1]!=s[j+i-1]) c++;
            a[j-i][j+i]=c;
        }
        c = 0;
        for(i=0;j-i-1>=1&&j+i<=n;i++){
            if(s[j-i-2]!=s[j+i-1]) c++;
            a[j-i-1][j+i]=c;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    fox(i,1,n){
        fox(j,1,k){
            fox(l,1,i){
                if(a[l][i]+dp[l-1][j-1]<dp[i][j]){
                    dp[i][j]=a[l][i]+dp[l-1][j-1];
                    lnk[i][j]=l;
                }
            }
        }
    }
    int ans = 1<<30, id = 0, p = n;
    fox(i,1,k){
        if(dp[n][i]<ans){
            ans = dp[n][i];
            id = i;
        }
    }
    while(p>0){
        fix(lnk[p][id],p);
        string t="";
        fox(i,lnk[p][id],p) t+=s[i-1];
        vec.insert(vec.begin(),t);
        p = lnk[p][id]-1; id--;
    }
    printf("%d\n",ans);
    fox(i,0,vec.size()-1) printf("%s%c",vec[i].c_str(),(i==vec.size()-1)?'\n':'+');
    return 0;
}