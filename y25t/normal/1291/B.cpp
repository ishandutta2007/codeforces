#include<cstdio>
#define N 300005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int l=0;
		while(a[l+1]>=l&&l<n)
			l++;
		int r=n+1;
		while(a[r-1]>=n+1-r&&r>1)
			r--;
		if(l>=r)
			printf("Yes\n");
		else
			printf("No\n");
	}
}