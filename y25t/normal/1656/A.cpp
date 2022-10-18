#include<bits/stdc++.h>
#define N 100005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%d %d\n",std::min_element(a+1,a+n+1)-a,std::max_element(a+1,a+n+1)-a);
	}
}