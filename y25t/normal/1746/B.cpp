#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		int res=0;
		for(int i=1;i<=n-s;i++)
			res+=a[i];
		printf("%d\n",res);
	}
}