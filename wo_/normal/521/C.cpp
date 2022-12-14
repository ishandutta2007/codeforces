#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long ex(long long a,long long e){
	if(e==0) return 1;
	long long res=ex(a,e/2);
	res*=res;
	res%=mod;
	if(e%2==1) res*=a;
	res%=mod;
	return res;
}

long long inv(long long a){
	return ex(a,mod-2);
}

long long p10[100100];
long long fact[100100];

long long C(int N,int K){
	if(N<K) return 0;
	long long tmp=fact[N];
	tmp*=inv(fact[K]);
	tmp%=mod;
	tmp*=inv(fact[N-K]);
	tmp%=mod;
	return tmp;
}

long long sum[100100];

char ch[100100];
int a[100100];

int N,K;

int main(){
	scanf("%d%d",&N,&K);
	scanf("%s",ch);
	for(int i=0;i<N;i++) a[i]=ch[i]-'0';
	p10[0]=1;
	for(int i=1;i<100100;i++){
		p10[i]=p10[i-1]*10;
		p10[i]%=mod;
	}
	fact[0]=1;
	for(int i=1;i<100100;i++) fact[i]=(fact[i-1]*i)%mod;
	if(K==0){
		long long ans=0;
		for(int i=N-1;i>=0;i--){
			ans+=p10[N-1-i]*a[i];
			ans%=mod;
		}
		ans+=mod;
		ans%=mod;
		printf("%d\n",(int)ans);
		return 0;
	}
/*	C[K-1]=1;
	for(int i=K-1;i+1<N;i++){
		long long tmp=C[i];
		tmp*=inv(i-K+2);
		tmp%=mod;
		tmp*=(i+1);
		tmp%=mod;
		C[i]=tmp;
	}*/
	sum[N-2]=C(N-2,K-1);
	for(int i=N-3;i>=K-1;i--){
	//	long long tmp=C[i]*p10[N-2-i];
	//	sum[i]=(sum[i+1]+tmp)%mod;
		long long tmp=C(i,K-1);
		tmp*=p10[N-2-i];
		tmp%=mod;
		sum[i]=sum[i+1]+tmp;
		sum[i]%=mod;
	}
	for(int i=K-2;i>=0;i--) sum[i]=sum[i+1];
	long long ans=0;
	for(int i=0;i<N-1;i++){
		ans+=(long long)a[i]*sum[i];
		ans%=mod;
	}
	for(int i=0;i<N;i++){
		if(i<K) continue;
		long long c=fact[i];
		c*=inv(fact[K]);
		c%=mod;
		c*=inv(fact[i-K]);
		c%=mod;
		long long tmp=c*a[i];
		tmp%=mod;
		tmp*=p10[N-1-i];
		tmp%=mod;
		ans+=tmp;
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}