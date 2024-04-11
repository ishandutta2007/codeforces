#include<bits/stdc++.h>
using namespace std;
int n,m,a[1009],b[1009],c[1009],d[1009];
int w[100009],v[100009],tot;
int f[1009];
int main(){
	scanf("%d%d%d%d",&n,&m,&c[0],&d[0]);
	for(int i=1;i<=m;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	tot=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i]/b[i];j++) w[++tot]=c[i],v[tot]=d[i];
	}
	memset(f,-1,sizeof(f));f[0]=0;
	for(int i=1;i<=tot;i++){
		for(int j=n;j>=0;j--){
			if(f[j]!=-1&&j+w[i]<=n)
				if(f[j+w[i]]<f[j]+v[i]) f[j+w[i]]=f[j]+v[i];
		}
	}
	int ans=0;
	for(int i=n;i>=0;i--)
		if(f[i]!=-1) f[i]+=((n-i)/c[0])*d[0],ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}