#include<bits/stdc++.h>

int T;

int n;

int cnt[105];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<=100;i++)
			cnt[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			cnt[abs(x)]++;
		}
		int ans=0;
		if(cnt[0])
			ans++;
		for(int i=1;i<=100;i++)
			ans+=std::min(cnt[i],2);
		printf("%d\n",ans);
	}
}