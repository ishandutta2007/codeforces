#include<bits/stdc++.h>
using namespace std;
long long a[15000000];
int tot=0;
long long b[15000000];
int n,k;
bool q[50]={};
int j[50];
long long ee[50];
int main(){
	scanf("%d%d",&n,&k);
	a[++tot]=0;
	while(k--){
		int qq;
		scanf("%d",&qq);
		for(int u=1;u<=qq;u++) scanf("%d",&j[u]);
		int ll=0;
		for(int u=1;u<=qq;u++)if(!q[j[u]]) ll++;
		ee[qq+1]=0;
		for(int u=qq;u>=1;u--) ee[u]=ee[u+1]^(1ll<<j[u]);
		int tot2=0;
		for(int i=1;i<=tot;i++){
			int u=0;
			for(int uu=1;uu<=qq;uu++)
				if((a[i]>>j[uu])&1) u++;
			a[i]&=(~ee[1]);
			for(int j=u;j<=ll+u;j++) b[++tot2]=(a[i]|ee[qq-j+1]);
		}
		tot=tot2;
		for(int i=1;i<=tot;i++) a[i]=b[i];
		for(int u=1;u<=qq;u++) q[j[u]]=true;
	}
	int ll=0;
	for(int i=1;i<=n;i++)if(!q[i]) ll++;
	if(ll>1){
		printf("REJECTED");
		return 0;
	}  
	if(ll==0){
		for(int j=1;j<=tot;j++){
			if(a[j]==0) continue;
			long long u=(a[j]&(-a[j]));
			a[j]+=u;
			if(a[j]!=(1ll<<(n+1))){
				printf("REJECTED");
				return 0;
			}
		}
		printf("ACCEPTED");
	}
	else{
		int j;
		for(int i=1;i<=n;i++)if(!q[i]) j=i;
		long long y=0;
		for(int i=1;i<=n;i++) y^=(1ll<<i);
		y^=(1ll<<j);
		for(int i=1;i<=tot;i++)
			if(y!=a[i]) {
				printf("REJECTED");
				return 0;
			}
		printf("ACCEPTED");
	}
	return 0;
}