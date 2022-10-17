#include<stdio.h>
#include<iostream>
using namespace std;
int T,n;
int cnt[3];
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0,y;
		scanf("%d",&n);
		for(int i=1,x;i<=n;i++)
			scanf("%d",&x),cnt[x%3]++;
		y=min(cnt[1],cnt[2]);
		ans+=cnt[0]+y+(cnt[1]-y)/3+(cnt[2]-y)/3;
		cnt[0]=cnt[1]=cnt[2]=0;
		printf("%d\n",ans);
	}
	return 0;
}