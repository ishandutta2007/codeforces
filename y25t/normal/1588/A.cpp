#include<bits/stdc++.h>
#define N 105

int T;

int n,a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		std::sort(a+1,a+n+1),std::sort(b+1,b+n+1);
		bool flg=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]&&a[i]+1!=b[i]){
				flg=0;
				break;
			}
		puts(flg?"YES":"NO");
	}
}