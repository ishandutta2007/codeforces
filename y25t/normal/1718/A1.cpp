#include<bits/stdc++.h>
#define N 100005

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		std::map<int,int> f;
		f[0]=0;
		int ans=0;
		for(int i=1,t=0;i<=n;i++){
			int x;
			scanf("%d",&x);
			t^=x;
			int tmp=f.count(t)?f[t]:-1;
			ans=f[t]=std::max(ans,tmp+1);
		}
		printf("%d\n",n-ans);
	}
}