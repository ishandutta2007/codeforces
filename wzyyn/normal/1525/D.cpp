#include<bits/stdc++.h>
using namespace std;

int n,a[5005];
int f[5005],g[5005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,30,sizeof(f));
	f[2501]=0;
	for (int i=1;i<=n;i++){
		memset(g,30,sizeof(g));
		if (a[i]==1){
			for (int j=0;j<=5002;j++)
				g[j+1]=f[j]+abs(2501-(j+1));
		}
		else{
			for (int j=0;j<=5002;j++)
				g[j]=min(f[j],f[j+1])+abs(2501-j);
		}
		memcpy(f,g,sizeof(f));
	}
	cout<<f[2501]<<endl;
}