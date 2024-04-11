#include<bits/stdc++.h>
using namespace std;
const int V=20000000;
int n;
int a[210000];
int is_p[V+10];
long long ans[V+10];
int num[V+10];
int tot=0;
int p[V+10];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)num[a[i]]++;
	for(int i=2;i<=V;i++)is_p[i]=1;
	for(int i=2;i<=V;i++){
		if(is_p[i]){
			p[++tot]=i;
			int k=V/i;
			for(int j=i;j<=k;j++) is_p[i*j]=0;
		}
	}//wmhischichiless
	for(int i=2;i<=V;i++){
		if(!is_p[i])continue;
		int j=V/i;
		for(int k=j;k>=1;k--)num[k]+=num[i*k];
	}
	for(int i=V;i>=1;i--){
		ans[i]=1ll*num[i]*i;
		for(int j=1;j<=tot;j++){
			if(p[j]*i>V)break;
			int k=p[j]*i;
			ans[i]=max(ans[i],ans[k]+1ll*(num[i]-num[k])*i);
		}
	}
	cout<<ans[1];
	return 0;
}