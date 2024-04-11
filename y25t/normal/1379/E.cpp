#include<cstdio>
#include<algorithm>
#define N 100005

int n,k;

inline bool chk(int x){
	return x-(x&-x)==0;
}

int ans[N];

int main(){
	scanf("%d%d",&n,&k);
	if(n%2==0||k>std::max((n-3)/2,0)||(n==9&&k==2)||(chk(n+1)&&k==1)||(!chk(n+1)&&k==0)){
		puts("NO");
		return 0;
	}
	puts("YES");
	int t=2*std::max(0,k-1);
	for(int i=1;i<t;i+=2){
		ans[i]=std::max(i-2,0);
		ans[i+1]=i;
	}
	if(t)
		ans[1+t]=t-1;
	for(int i=1;(i<<1)<n-t;i++)
		ans[(i<<1)+t]=ans[(i<<1|1)+t]=i+t;
	if(chk(n-t+1)&&k)
		ans[n-1]=ans[n]=2;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}