#include<bits/stdc++.h>
#define N 100005

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int n,a[N];

std::mt19937 rng(19260817);

int p[N];

int ans[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::iota(p,p+n+1,0);
	for(int _=0;_<(int)1e7/std::max(22,n);_++){
		std::shuffle(p+1,p+n+1,rng);
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			if(y&&x!=gcd(x,a[p[i]])){
				ans[p[i]]=1;
				x=gcd(x,a[p[i]]);
			}
			else{
				ans[p[i]]=2;
				y=gcd(y,a[p[i]]);
			}
		}
		if(x==1&&y==1){
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d ",ans[i]);
			return 0;
		}
	}
	puts("NO");
}