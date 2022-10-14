#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

int main(){
    for(int t=ri();t--;){
        int n,m;rd(n,m);
        auto a=rv<int>(n),b=rv<int>(n);
        ll sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum<m){
            printf("-1\n");
            continue;
        }
        vector<int> A,B;
        for(int i=0;i<n;i++){
            if(b[i]==1)A.pb(a[i]);
            else B.pb(a[i]);
        }
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());
        int ans=4*n;
        ll pref[n];
        for(int i=0;i<(int)B.size();i++){
            if(i==0)pref[i]=B[i];
            else pref[i]=pref[i-1]+B[i];
            if(pref[i]>=m)ans=min(ans,(i+1)*2);
        }
        ll s=0;
        for(int i=0;i<(int)A.size();i++){
            s+=A[i];
            if(s>=m){
                ans=min(ans,i+1);
                break;
            }
            if(B.empty())continue;
            int need=m-s;
            if(need>pref[(int)B.size()-1]){
                continue;
            }
            int bot=0,top=(int)B.size()-1,j=0;
            while(bot<=top){
                int mid=bot+top>>1;
                if(pref[mid]+s>=m){
                    top=mid-1;
                    j=mid;
                }else bot=mid+1;
            }
            ans=min(ans,i+1+(j+1)*2);
        }
        printf("%i\n",ans);
    }
	return 0;
}