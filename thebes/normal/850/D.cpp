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

const int MN = 35, MX = 80;
int n, i, j, k, arr[MN], ok[MN][MX][MX*MX], grid[MX][MX];

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+n+1);
    ok[0][0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<MX;j++){
            for(k=arr[i];k<MX*MX;k++){
                if(k>=j*(j-1)/2&&(ok[i][j-1][k-arr[i]]||ok[i-1][j-1][k-arr[i]]))
                    ok[i][j][k]=1;
            }
        }
    }
    vector<pii> ans;
    int x, y, z, sna=1<<30;
    for(i=1;i<MX;i++){
        for(j=1;j<MX*MX;j++){
            if(ok[n][i][j]&&i*(i-1)/2==j){
                sna=i,x=n,y=i,z=j;
                break;
            }
        }
        if(sna!=(1<<30)) break;
    }
    if(n==1&&arr[1]==0){
        printf("1\n0\n");
        return 0;
    }
    if(sna==(1<<30)) printf("=(\n");
    else{
        int nxt=0;
        while(x>=1){
            ans.pb({arr[x],nxt++});
            y--, z-=arr[x];
            if(!ok[x][y][z]) x--;
        }
        printf("%d\n",ans.size());
        int sz=ans.size();
        sort(ans.begin(),ans.end(),[](pii i,pii j){return i.first<j.first;});
        while(ans.size()){
            pii cur=ans.back();
            ans.pop_back();
            for(i=0;i<ans.size();i++){
                grid[cur.second][ans[i].second]=1;
                if(i>=cur.first){
                    grid[cur.second][ans[i].second]^=1;
                    grid[ans[i].second][cur.second]^=1;
                    ans[i].first--;
                }
            }
            sort(ans.begin(),ans.end(),[](pii i,pii j){return i.first<j.first;});
        }
        for(i=0;i<sz;i++){
            for(j=0;j<sz;j++){
                printf("%d",grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}