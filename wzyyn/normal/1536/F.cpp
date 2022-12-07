#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
const int mo=1000000007;
int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo; 
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int i=(n+1)/2;i<=n;i++)
		if (i%2==0){
			int w=(2ll*C(i,n-i)+mo-C(i-1,n-i))%mo;
			ans=(ans+2ll*fac[i]%mo*w)%mo;
		}
	cout<<ans<<endl;
}