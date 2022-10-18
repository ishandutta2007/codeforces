#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,k,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		bool flg=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),flg|=a[i];
		puts(flg?"YES":"NO");
	}
}