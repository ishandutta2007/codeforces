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

const int MN = 1e6+5, mod = 1e9+9, mod2 = 1e9+7;
int n, tc, pw[MN]={1}, pw2[MN]={1}, fhsh[MN][2], bhsh[MN][2], i, j, lo, hi, flen[MN], blen[MN];
inline pii getf(int x,int y){
    pii ret={(fhsh[y][0]-1LL*fhsh[x-1][0]*pw[y-x+1])%mod,(fhsh[y][1]-1LL*fhsh[x-1][1]*pw2[y-x+1])%mod2};
    while(ret.first<0) ret.first+=mod;
    while(ret.second<0) ret.second+=mod2;
    return ret;
}
inline pii getb(int x,int y){
    pii ret={(bhsh[x][0]-1LL*bhsh[y+1][0]*pw[y-x+1])%mod,(bhsh[x][1]-1LL*bhsh[y+1][1]*pw2[y-x+1])%mod2};
    while(ret.first<0) ret.first+=mod;
    while(ret.second<0) ret.second+=mod2;
    return ret;
}
string s, t;

int main(){
    for(i=1;i<MN;i++){
        pw[i]=1LL*pw[i-1]*133%mod;
        pw2[i]=1LL*pw2[i-1]*133%mod2;
    }
    for(scanf("%d",&tc);tc;tc--){
        cin >> s;
        n = s.size();
        for(i=1;i<=n;i++){
            fhsh[i][0]=(1LL*fhsh[i-1][0]*133+s[i-1]-'a'+1)%mod;
            fhsh[i][1]=(1LL*fhsh[i-1][1]*133+s[i-1]-'a'+1)%mod2;
        }
        bhsh[n+1][0]=bhsh[n+1][1]=0;
        for(i=n;i>=1;i--){
            bhsh[i][0]=(1LL*bhsh[i+1][0]*133+s[i-1]-'a'+1)%mod;
            bhsh[i][1]=(1LL*bhsh[i+1][1]*133+s[i-1]-'a'+1)%mod2;
        }
        int lb=-1;
        for(i=1;i<=n;i++){
            lo=n-i+1;
            if(lo>i) blen[i]=0;
            else{
                if(lb==-1) lb=i;
                if(lb!=i){
                    if(lb-1>=lo&&getf(lb-1,i)==getb(lb-1,i)) lb--;
                    else{
                        while(getf(lb,i)!=getb(lb,i)) lb++;
                    }
                }
                else if(lb-1>=lo&&getf(lb-1,i)==getb(lb-1,i)) lb--;
                blen[i]=i-lb+1;
            }
        }
        lb = -1;
        for(i=n;i>=1;i--){
            lo=n-i+1;
            if(lo<i) flen[i]=0;
            else{
                if(lb==-1) lb=i;
                if(lb!=i){
                    if(lb+1<=lo&&getf(i,lb+1)==getb(i,lb+1)) lb++;
                    else{
                        while(getf(i,lb)!=getb(i,lb)) lb--;
                    }
                }
                else if(lb+1<=lo&&getf(i,lb+1)==getb(i,lb+1)) lb++;
                flen[i]=lb-i+1;
            }
        }
        t.clear();
        pii ans(1,0);
        for(i=0;i<s.size()/2;i++){
            if(2*i+max(flen[i+1],blen[n-i])>ans.first){
                ans.first = 2*i+max(flen[i+1],blen[n-i]);
                ans.second = i;
            }
            if(s[i]!=s[n-i-1]) break;
        }
        for(i=0;i<ans.second;i++)
            t += s[i];
        if(flen[ans.second+1]>blen[n-ans.second]){
            for(i=0;i<flen[ans.second+1];i++)
                t += s[ans.second+i];
        }
        else{
            for(i=blen[n-ans.second]-1;i>=0;i--)
                t += s[n-ans.second-i-1];
        }
        for(i=ans.second-1;i>=0;i--)
            t += s[n-i-1];
        printf("%s\n",t.c_str());
    }
    return 0;
}