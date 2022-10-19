#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[100100],mn,tot[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mn=n;
		for(int i=1;i<=n;i++)cnt[i]=tot[i]=0; 
		for(int i=1,x;i<=n;i++)scanf("%d",&x),cnt[x]++;
		for(int i=1;i<=n;i++)tot[cnt[i]]++;
		for(int i=2;i<=n;i++){
			if(!tot[i])continue;
			mn=min(mn,(n-tot[i])/(i-1)-1);
		}
		printf("%d\n",mn);
	}
	return 0;
}