#include"algorithm"
#include"iostream"
#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"math.h"
#include"vector"
#include"queue"
#include"set"
#include"map"

using namespace std;
typedef long long LL;

template<class I>
void gi(I&x){
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	x=ch&15;
	for(ch=getchar();ch<='9'&&ch>='0';ch=getchar())x=x*10+(ch&15);
}

const int N=300005,P=1E9+7;

int power(int a,int t){
	int r=1;
	while(t){
		if(t&1)r=(LL)r*a%P;
		a=(LL)a*a%P;t>>=1;
	}
	return r;
}

bool fl[N];
int pri[N],n,m,pcnt,a[N],w[N],fac[N],ifac[N],lst[N],ans,val[N],sum[N];

int C(int n,int m){
	if(n<m)return 0;
	return (LL)fac[n]*ifac[m]%P*ifac[n-m]%P;
}

void up(int&x,int y){x+=y;x<P?:x-=P;}
void dn(int&x,int y){x-=y;x>=0?:x+=P;}

int calc(int k){
	register int res=0,s;
	s=0,up(s,sum[n-1]),dn(s,sum[k-1]),up(res,(LL)s*k%P);
	s=0,up(s,sum[n-1]),dn(s,sum[n-k]),up(res,(LL)s*(n-k)%P);
	return res;
}

int main(){
	gi(n);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(LL)fac[i-1]*i%P;
	ifac[n]=power(fac[n],P-2);
	for(int i=n;i;i--)ifac[i-1]=(LL)ifac[i]*i%P;
	for(int i=1;i<=n;i++)gi(a[i]),m=max(m,a[i]);
	for(int i=2;i<=m;i++){
		if(!fl[i]){
			pri[++pcnt]=i;
			lst[i]=i;
		}
		for(int j=1;j<=pcnt&&i*pri[j]<=m;j++){
			fl[i*pri[j]]=true,lst[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	for(int i=1;i<=n;i++){
		int x=1,y=a[i],t=1;
		while(y!=1){
			if(x==lst[y])t*=x;
			else x=lst[y],t=x;
			w[t]++,y/=lst[y];
		}
	}
	for(int i=0;i<n;i++){
		val[i]=C(n-1,i);
		if(i)sum[i]=sum[i-1];else sum[i]=0;
		up(sum[i],val[i]);
	}
	for(int i=2;i<=m;i++){
		if(w[i]==0||w[i]==n)continue;
		up(ans,calc(w[i]));
	}
	printf("%d\n",ans);
	return 0;
}