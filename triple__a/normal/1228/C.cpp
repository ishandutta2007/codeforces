#include<bits/stdc++.h>
using namespace std;

const int maxn=107;
const int mod=1e9+7;

int p[maxn],cnt=0,x;
long long n,ans=0;

void decomp(int u){
	int v=sqrt(u);
	for (int i=2;i<=v;++i){
		if (u%i==0){
			p[++cnt]=i;
		}
		while (u%i==0){
			u/=i;
		}
	}
	if (u>1) p[++cnt]=u;
}

long long quick_power(long long x,long long y){
	long long ans=1,t=x;
	while (y){
		if (y&1){
			ans=(ans*t)%mod;
		}
		y>>=1;
		t=(t*t)%mod;
	}
	return ans;
}


long long count(long long n,int p){
	long long ans=0;
	while (n){
		n/=p;
		ans+=n;
	}
	return ans;
}

int main(){
	cin>>x>>n;
	decomp(x);
	ans=1;
	for (int i=1;i<=cnt;++i){
		ans=(ans*quick_power(p[i],count(n,p[i])))%mod;
	}
	cout<<ans<<endl;
	return 0;
}