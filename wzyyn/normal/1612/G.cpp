#include<bits/stdc++.h>

using namespace std;

const int mo=1000000007;
const int N=1000005;
int n,x;
int c[N],fac[N];
long long sum,ans;
void init(){
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		++c[x];
		sum+=x;
	}
	int mx=0,way=1;
	for (int i=N-1;i>=2;i--){
		if (!c[i]) continue;
		mx=(mx+1ll*(sum-c[i])%mo*c[i]%mo*(i-1))%mo;
		way=1ll*way*fac[c[i]]%mo*fac[c[i]]%mo;
		sum-=2*c[i];
		c[i-2]+=c[i];
	}
	way=1ll*way*fac[c[1]]%mo;
	cout<<mx<<' '<<way<<endl;
}