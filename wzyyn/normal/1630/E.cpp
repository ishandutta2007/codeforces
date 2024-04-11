#include<bits/stdc++.h>

using namespace std;

const int mo=998244353;
const int N=1000005;
int fac[N],inv[N],phi[N];
int n,x,s[N],q[N];
int ans0,ans1;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	for (int i=1;i<N;i++) phi[i]=i;
	for (int i=1;i<N;i++)
		for (int j=2;i*j<N;j++)
			phi[i*j]-=phi[i];
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int IC(int x,int y){
	return 1ll*inv[x]*fac[y]%mo*fac[x-y]%mo;
}

void solve(int v){
	int sum=0;
	int w1=1,w2=0;
	for (int i=1;i<=*q;i++){
		int x=s[q[i]]/v;
		w1=1ll*w1*C(sum+x,x)%mo;
		sum+=x;
	}
	for (int i=1;i<=*q;i++){
		int x=s[q[i]]/v;
		if (x>=2) w2=(w2+1ll*w1*IC(sum,x)%mo*C(sum-2,x-2)%mo*n)%mo;
	}
	ans0=(ans0+1ll*phi[v]*w2)%mo;
	ans1=(ans1+1ll*phi[v]*w1)%mo;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) s[i]=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&x),++s[x];
	int g=*q=0;
	for (int i=1;i<=n;i++)
		if (s[i]!=0){
			q[++*q]=i;
			g=gcd(g,s[i]);
		}
	if (*q==1){
		puts("1");
		return;
	}
	ans0=0,ans1=0;
	for (int i=1;i<=g;i++)
		if (g%i==0) solve(i);
	//cout<<ans0<<' '<<ans1<<endl;
	ans0=1ll*ans0*inv[n]%mo*fac[n-1]%mo;
	ans1=1ll*ans1*inv[n]%mo*fac[n-1]%mo;
	ans0=1ll*ans0*power(ans1,mo-2)%mo;
	printf("%d\n",(n+mo-ans0)%mo);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}