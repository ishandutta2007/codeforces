#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,x,y,u,v;
ll gcd(ll a,ll b){if(!b) return a;return gcd(b,a%b);}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1,y=0;return a;}
    ll t=exgcd(b,a%b,y,x);y-=(a/b)*x;return t;
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&x,&y,&u,&v);
    if(u==0||v==0){
        if(u==0&&v==0){printf("-1\n");return 0;}
        if(u==0){
            if(x==0){if(v==1) printf("0 %lld\n",m);else printf("0 0\n");return 0;} 
            if(x==n){if(v==1) printf("%lld %lld\n",n,m);else printf("%lld 0\n",n);return 0;}
        }
        if(v==0){
            if(y==0){if(u==1) printf("%lld 0\n",n);else printf("0 0\n");return 0;}
            if(y==m){if(u==1) printf("%lld %lld\n",n,m);else printf("0 %lld\n",m);return 0;}
        }
        printf("-1\n");
        return 0;
    }
    if(u==-1) x=n-x;
    if(v==-1) y=m-y;
    ll a,b;
    ll g=exgcd(n,m,a,b);
    if((x-y)%g){printf("-1\n");return 0;}
    a=a*(x-y)/g%(m/g);
    if(a<=0) a+=(m/g);
    ll xx=a*n,yy=y-x+xx;
    xx/=n,yy/=m;
    int ansx=(xx&1),ansy=(yy&1);
    ansx^=(u==-1),ansy^=(v==-1);
    printf("%lld %lld\n",ansx*n,ansy*m);
    return 0;
}