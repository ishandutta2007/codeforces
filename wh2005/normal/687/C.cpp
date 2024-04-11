#include<bits/stdc++.h>
using namespace std;
int n,k,a[509],f[509];
int ans[509][509];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,-1,sizeof(f));
	memset(ans,-1,sizeof(ans));
	f[0]=1,ans[0][0]=1;
	for(int i=1;i<=k;i++) ans[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=k;j>=0;j--){
			if(f[j]!=-1&&j+a[i]<=k){
				f[j+a[i]]=1;
				for(int p=k;p>=0;p--){
					if(ans[j][p]!=-1){
						if(p+a[i]<=k) ans[j+a[i]][p+a[i]]=1;
						ans[j+a[i]][p]=1;
					}
				}
			}
		}
	}
	int sum=0;
	for(int p=k;p>=0;p--) if(ans[k][p]!=-1) sum++;
	printf("%d\n",sum);
	for(int i=0;i<=k;i++)
		if(ans[k][i]!=-1) printf("%d ",i);
	return 0;
}