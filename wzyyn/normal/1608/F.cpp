#include<bits/stdc++.h>

using namespace std;

const int N=2005;
const int mo=998244353;
int n,k;
int l[N],r[N];
int fac[N],inv[N];
int f[105][N],g[105][N];
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
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		r[i]=min(n+1,l[i]+k);
		l[i]=max(0,l[i]-k);
	}
	for (int i=2;i<=n;i++)
		l[i]=max(l[i],l[i-1]);
	for (int i=n;i>=2;i--)
		r[i-1]=min(r[i-1],r[i]);
	for (int i=1;i<=n;i++)
		if (l[i]>r[i])
			return puts("0"),0;
	l[0]=r[0]=0; f[0][0]=1;
	for (int i=1;i<=n;i++){
		memset(g,0,sizeof(g));
		for (int j=l[i-1];j<=r[i-1];j++)
			for (int k=0;k+j<=i;k++){
				int p=max(1,l[i]-j);
				if (p-1>k||j+p>r[i]) continue;
				g[j+p-l[i]][k-(p-1)]=(g[j+p-l[i]][k-(p-1)]+1ll*f[j-l[i-1]][k]*fac[k]%mo*inv[k-(p-1)])%mo;
			}
		for (int j=l[i];j<r[i];j++)
			for (int k=1;k+j<=i+1;k++)
				g[j+1-l[i]][k-1]=(g[j+1-l[i]][k-1]+1ll*g[j-l[i]][k]*k)%mo;
		for (int j=l[i-1];j<=r[i-1];j++)
			for (int k=0;k+j<=i;k++)
				if (l[i]<=j&&j<=r[i]){
					g[j-l[i]][k]=(g[j-l[i]][k]+1ll*f[j-l[i-1]][k]*(k+j))%mo;
					g[j-l[i]][k+1]=(g[j-l[i]][k+1]+1ll*f[j-l[i-1]][k])%mo;
				}
		memcpy(f,g,sizeof(f));
	}
	int ans=0;
	for (int j=l[n];j<=r[n];j++)
		for (int k=0;k+j<=n+1;k++){
			int re=max(0,n-j);
			if (re>=k) ans=(ans+1ll*f[j-l[n]][k]*fac[re]%mo*inv[re-k])%mo;
		}
	cout<<ans<<endl;
}