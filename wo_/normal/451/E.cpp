#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long ex(long long a,long long e){
	if(e==0) return 1;
	long long tmp=ex(a,e/2);
	tmp*=tmp;
	tmp%=mod;
	if(e%2==1) tmp*=a;
	tmp%=mod;
	return tmp;
}

long long inv(long long a){
	return ex(a,mod-2);
}

long long invs[22];

long long C(long long n,long long k){
	if(k<0||n<k) return 0;
	long long ans=1;
	for(int i=0;i<k;i++){
		ans*=((n-i)%mod);
		ans%=mod;
		ans*=invs[i+1];
		ans%=mod;
	}
	return ans;
}

long long f[22];
long long S;
long long dp[1<<20];

int main(){
	for(int i=0;i<22;i++) invs[i]=inv(i);
	int N;
	cin>>N>>S;
	for(int i=0;i<N;i++) cin>>f[i];
	for(int stat=0;stat<(1<<N);stat++){
		int cnt=0;
		long long x=0;
		for(int j=0;j<N;j++) if((stat>>j)&1){
			cnt++;
			x+=(f[j]+1);
		}
		dp[stat]=C(S-x+N-1,N-1);
	}
	long long ans=0;
	for(int stat=0;stat<(1<<N);stat++){
		int cnt=0;
		for(int i=0;i<N;i++) if((stat>>i)&1) cnt^=1;
		if(cnt==1) ans-=dp[stat];
		else ans+=dp[stat];
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}