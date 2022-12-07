#include<bits/stdc++.h>

using namespace std;

const int N=5005;
const int mo=998244353;
int fac[N],inv[N];
int n,k,a[N],q[N];
char s[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int main(){
	init();
	scanf("%d%d%s",&n,&k,s+1);
	int ans=1;
	for (int i=1;i<=n;i++){
		a[i]=a[i-1]+s[i]-'0';
		if (s[i]=='1') q[++*q]=i;
	}
	if (*q>=k){
		int v=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='1'){
				int p=((v+k+1)>*q?n:q[v+k+1]-1);
				//cout<<i<<' '<<p<<endl;
				int v1=a[p]-a[i-1],v0=(p-i+1)-v1;
				if (v0) ans=(ans+1ll*fac[v0+v1-1]*inv[v0-1]%mo*inv[v1])%mo;
			}
			else if (k){
				int p=((v+k+1)>*q?n:q[v+k+1]-1);
				//cout<<i<<' '<<p<<endl;
				int v1=a[p]-a[i-1],v0=(p-i+1)-v1;
				if (v1) ans=(ans+1ll*fac[v0+v1-1]*inv[v0]%mo*inv[v1-1])%mo;
			}
			v+=(s[i]=='1');
		}
	}
	cout<<ans<<endl;
}