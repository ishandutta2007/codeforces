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
    for(int t=ri();t>0;t--){
        int n=ri();
        long long a[n+1];
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        long long prefm[n+2];
        prefm[0]=0;
        for(int i=1;i<=n;i++)prefm[i]=max(prefm[i-1],a[i]);
        long long sufm[n+2];
        sufm[n+1]=0;
        for(int i=n;i>=1;i--)sufm[i]=max(sufm[i+1],a[i]);
        /*long long sum=0,sum2=0;
        for(int i=0;i<n;i++)sum+=a[i];
        for(int i=0;i<n;i++){
            if((a[i]%(n-1))!=0)sum2+=n-1-(a[i]%(n-1));
        }
        long long ans=1e18;
        for(int i=0;i<n;i++){
            long long sum3=sum2;
            if((a[i]%(n-1))!=0)sum3-=n-1-(a[i]%(n-1));
            if(a[i]<=sum3)ans=min(ans,sum3-a[i]);
            else{
                long long x=a[i]-sum,sz=n-1;
                if((x%sz)==0)ans=0;
                else ans=min(ans,sz-x%sz);
            }
        }*/
        long long sum=0;
        for(int i=1;i<=n;i++)sum+=a[i];
        long long ans=(long long)0;
        for(int i=1;i<=n;i++){
            long long tmp=0,sum1=sum-a[i],mx=max(prefm[i-1],sufm[i+1]);
            long long k1=mx*(n-1)-sum1;
            if(a[i]<=k1)tmp=k1-a[i];
            else{
                long long x=a[i]-k1,sz=n-1;
                if(x%sz==0)tmp=0;
                else tmp=sz-x%sz;
            }
            ans=max(ans,tmp);
        }
        printf("%lld\n",ans);
    }
	return 0;
}