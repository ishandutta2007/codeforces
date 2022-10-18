#include<bits/stdc++.h>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			ans+=(1+(!x))*i*(n-i+1);
		}
		printf("%d\n",ans);
	}
}