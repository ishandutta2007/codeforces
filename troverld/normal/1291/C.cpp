#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,num[4010],mn,mx;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k),k=min(k,m-1),mx=0;
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=0;i<=k;i++){
			mn=0x3f3f3f3f;
			for(int j=0;j<=m-k-1;j++)mn=min(mn,max(num[i+j+1],num[n-(k-i)-(m-k-1-j)]));
			mx=max(mx,mn);
		}
		printf("%d\n",mx);
	}
	return 0;
}