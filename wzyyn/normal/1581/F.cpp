#include<bits/stdc++.h>

using namespace std;

const int N=4005;
int n,m,a[N];
long long f[N][N],tmp[N];

int build(int l,int r){
	if (l>r) return 0;
	int k=l;
	for (int i=l;i<=r;i++)
		if (a[i]<a[k]) k=i;
	int ls=build(l,k-1);
	int rs=build(k+1,r);
	if (ls){
		for (int i=0;i<=k-l;i++)
			f[ls][i]+=1ll*(a[ls]-a[k])*i*(m-i);
		memset(tmp,0,sizeof(tmp));
		for (int i=0;i<=k-l;i++)
			for (int j=0;j<=1;j++)
				tmp[i+j]=max(tmp[i+j],f[ls][i]+f[k][j]);
		memcpy(f[k],tmp,sizeof(tmp));
	}
	if (rs){
		for (int i=0;i<=r-k;i++)
			f[rs][i]+=1ll*(a[rs]-a[k])*i*(m-i);
		memset(tmp,0,sizeof(tmp));
		for (int i=0;i<=r-k;i++)
			for (int j=0;j<=k-l+1;j++)
				tmp[i+j]=max(tmp[i+j],f[rs][i]+f[k][j]);
		memcpy(f[k],tmp,sizeof(tmp));
	}
	return k;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int p=build(1,n);
	cout<<f[p][m]<<endl;
}