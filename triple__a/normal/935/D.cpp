#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

const int maxn=500007;
const int mod=1e9+7;
LL ep,eq,gp,gq; 
int a[maxn],b[maxn];

void plusD(LL p1,LL q1,LL p2,LL q2,LL &p,LL &q){
	q=(q1*q2)%mod;
	p=(p1*q2+p2*q1)%mod;
}

LL exgcd(LL l,LL r,LL &x,LL &y){
    if(r==0){x=1;y=0;return l;}
    else
    {
        LL d=exgcd(r,l%r,y,x);
        y-=l/r*x;
        return d;
    }
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	ep=eq=gq=1,gp=0;
	for (int i=1;i<=n;++i){
		LL p,q;
		if (a[i]==0){
			if (b[i]==0){
				plusD(((m-1)*ep)%mod,(2*m*eq)%mod,gp,gq,p,q);
				gp=p,gq=q;
			}
			else{
				plusD(((m-b[i])*ep)%mod,(m*eq)%mod,gp,gq,p,q);
				gp=p,gq=q;	
			}
			eq=(m*eq)%mod;
		}
		else{
			if(b[i]==0){
				plusD(((a[i]-1)*ep)%mod,(m*eq)%mod,gp,gq,p,q);
				gp=p,gq=q;
				eq=(m*eq)%mod;
			}
			else{
				if (a[i]==b[i]) continue;
				if (a[i]>b[i]){
					plusD(ep,eq,gp,gq,p,q);
					gp=p,gq=q;
				}
				break;
			}
		}
	}
	
	LL ans,tmp;
	exgcd(gq,mod,ans,tmp);
	ans=(ans+mod)%mod;
	ans=(ans*gp)%mod;
	printf("%lld\n",ans);
	return 0;
}