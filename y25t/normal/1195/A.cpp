#include<cstdio>
#define N 1005 

int n,k;

int cnt[N];

int ans;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=1;i<=k;i++)
		if(cnt[i]&1)
			ans++;
	printf("%d",n-ans/2);
}