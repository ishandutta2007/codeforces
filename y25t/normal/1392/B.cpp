#include<cstdio>
#include<algorithm>
#define ll long long
#define N 200005
 
int T;
 
int n,a[N];
ll k;
 
int mx;
 
int main(){
	scanf("%d",&T);
	while(T--){
		mx=-1e9;
		scanf("%d%I64d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			mx=std::max(mx,a[i]);
		k--;
		for(int i=1;i<=n;i++)
			a[i]=mx-a[i];
		mx=-1e9;
		for(int i=1;i<=n;i++)
			mx=std::max(mx,a[i]);
		for(int i=1;i<=n;i++)
			printf("%d ",(k&1)?mx-a[i]:a[i]);
		puts("");
	}
}