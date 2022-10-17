#include<stdio.h>
int T,s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&s);
		int now=1,ans=0;
		while(s>now)
			s-=now,now+=2,ans++;
		if(now)
			ans++;
		printf("%d\n",ans); 
	}
	return 0;
}