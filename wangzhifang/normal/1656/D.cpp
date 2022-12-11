//https://www.luogu.com.cn/blog/_post/118765 
#include<bits/stdc++.h>
using namespace std;
#define rg register
#define RP(i,a,b) for(register int i=a;i<=b;++i)
#define DRP(i,a,b) for(register int i=a;i>=b;--i)
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
typedef long long ll;
typedef double db;
#define lll __int128

ll min_factor,n;

inline ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

inline ll qp(ll x,ll p,ll mod)
{
    ll ans=1;
    while(p)
    {
        if(p&1)
            ans=(lll)ans*x%mod;
        x=(lll)x*x%mod;
        p>>=1;
    }
    return ans;
}

inline bool mr(ll x,ll b)
{
    ll k=x-1;
    while(k)
    {
        ll cur=qp(b,k,x);
        if(cur!=1 && cur!=x-1)
            return false;
        if((k&1)==1 || cur==x-1)
            return true;
        k>>=1;
    }
    return true;
}

inline bool prime(ll x)
{
    if(x==46856248255981ll || x<2)
        return false;
    if(x==2 || x==3 || x==7 || x==61 || x==24251)
        return true;
    return mr(x,2)&&mr(x,61);
}

inline ll f(ll x,ll c,ll n)
{
    return ((lll)x*x+c)%n;
}

inline ll PR(ll x)
{
    ll s=0,t=0,c=1ll*rand()%(x-1)+1;
    int stp=0,goal=1;
    ll val=1;
    for(goal=1;;goal<<=1,s=t,val=1)
    {
        for(stp=1;stp<=goal;++stp)
        {
            t=f(t,c,x);
            val=(lll)val*abs(t-s)%x;
            if((stp%127)==0)
            {
                ll d=gcd(val,x);
                if(d>1)
                    return d;
            }
        }
        ll d=gcd(val,x);
        if(d>1)
            return d;
    }
}

inline bool fac(ll x)
{
    if(x<2)
        return 0;
//    printf("*%lld\n",x);
    if(x*lll(x+1)/2<=n)
    {
        min_factor=x;
        return 1;		
    }
    if(prime(x))
    	return 0;
    ll p=x;
    while(p>=x)
        p=PR(x);
    while((x%p)==0)
        x/=p;
    if(fac(x))
    	return 1;
    if(fac(p))
    	return 1;
    return 0;
}

int main()
{
    srand((unsigned)time(NULL));
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ll t=n;
        while(!(t&1))
        	t>>=1;
        if(t==1){
        	puts("-1");
        	continue;
		}
//        printf("&%lld\n",t);
    	ll tmp=n/t*2;
    	if(tmp*lll(tmp+1)/2<=n){
    		printf("%lld\n",tmp);
    		continue;
		}
		min_factor=t;
        fac(t);
        if(min_factor*lll(min_factor+1)/2<=n)
        	printf("%lld\n",min_factor);
        else
			puts("-1");
    }
    return 0;
}