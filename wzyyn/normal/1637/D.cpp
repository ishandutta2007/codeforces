#include<bits/stdc++.h>

using namespace std;

const int N=105;
int n,a[N],b[N];
int f[N*N],g[N*N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++)
		f[0]+=(n-1)*(a[i]*a[i]+b[i]*b[i]);
	int l=0,r=0,s=0;
	for (int i=1;i<=n;i++){
		memset(g,60,sizeof(g));
		for (int j=l;j<=r;j++){
			int k=s-j;
			g[j+a[i]]=min(g[j+a[i]],f[j]+2*j*a[i]+2*k*b[i]);
			g[j+b[i]]=min(g[j+b[i]],f[j]+2*j*b[i]+2*k*a[i]);
		}
		memcpy(f,g,sizeof(f));
		l+=min(a[i],b[i]);
		r+=max(a[i],b[i]);
		s+=a[i]+b[i];
	}
	printf("%d\n",*min_element(f+l,f+r+1));
		
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}