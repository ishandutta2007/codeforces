#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long fact[100100];
long long invFact[100100];

long long a[101000][110];

long long ex(long long a,long long n){
	if(n==0) return 1;
	long long res=ex(a,n/2);
	res*=res;
	res%=mod;
	if(n%2==1) res*=a;
	res%=mod;
	return res;
}

long long inv(long long a){
	return ex(a,mod-2);
}

long long C(int n,int k){
	long long res=fact[n];
	res*=invFact[k];
	res%=mod;
	res*=invFact[n-k];
	res%=mod;
	return res;
}

void add(int l,int r,int k){
	a[l+200-k][k]++;
	a[l+200-k][k]%=mod;
	for(int i=0;i<=k;i++){
		a[r+1+200][i]-=C(r-l+k+1,k-i);
		a[r+1+200][i]%=mod;
	}
}

void get(){
	for(int i=0;i<101000-1;i++){
		for(int j=0;j<105;j++){
			a[i+1][j]=(a[i+1][j]+a[i][j])%mod;
			if(j!=0) a[i+1][j-1]=(a[i+1][j-1]+a[i][j])%mod;
		}
	}
}

int ini[100100];

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	fact[0]=1;
	invFact[0]=1;
	for(int i=1;i<100100;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
		invFact[i]=inv(fact[i]);
	}
	for(int i=0;i<N;i++) scanf("%d",ini+i);
	for(int i=0;i<M;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		l--;r--;
		add(l,r,k);
	}
	get();
	for(int i=0;i<N;i++){
		long long ans=a[i+200][0];
		ans+=ini[i];
		ans%=mod;
		ans+=mod;
		ans%=mod;
		printf("%d%c",(int)ans,i==N-1?'\n':' ');
	}
	return 0;
}