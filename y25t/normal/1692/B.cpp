#include<bits/stdc++.h>

int T;

int n,a[55],cnt[10005];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int t=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),t+=cnt[a[i]]>0,cnt[a[i]]++;
		printf("%d\n",n-(t+(t&1)));
		for(int i=1;i<=n;i++)
			cnt[a[i]]--;
	}
}