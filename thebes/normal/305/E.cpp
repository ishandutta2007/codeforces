#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
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
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 5005;
int nim[MN], cnt[MN], n, i, j, m[MN], a[MN], b[MN];
string s;

int main(){
    cin >> s; n = s.size();
    fox(i,1,n){
        memset(cnt,0,sizeof(cnt));
        fox(j,1,i){
            cnt[nim[max(0,j-2)]^nim[max(0,i-j-1)]]=1;
        }
        fox(j,0,MN){
            if(!cnt[j]){
                nim[i]=j;
                break;
            }
        }
    }
    s.insert(s.begin(),' ');
    int wew = 0;
    for(i=2;i<=n-1;i++){
        if(s[i-1]==s[i+1]){
            for(j=i;j<=n-1&&s[j-1]==s[j+1];j++) a[j]=a[j-1]+1;
            wew ^= nim[j-i];
            int sz = j-i; b[i] = sz;
            for(j=i;j<=n-1&&s[j-1]==s[j+1];j++) m[j]=sz,b[j]=j==i?b[j]:b[j-1]-1;
            i=j;
        }
    }
    if(wew){
        printf("First\n");
        for(j=2;j<=n-1;j++){
            if(m[j]&&(wew^nim[m[j]]^nim[max(0,a[j]-2)]^nim[max(0,b[j]-2)])==0){
                printf("%d\n",j);
                break;
            }
        }
    }
    else printf("Second\n");
    return 0;
}