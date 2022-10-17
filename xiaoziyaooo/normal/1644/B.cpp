#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==3){
			puts("3 2 1\n1 3 2\n3 1 2");
			continue;
		}
		for(int i=2;i<=n;i++){
			for(int j=i;j<=n;j++)
				printf("%d ",j);
			for(int j=2;j<i;j++)
				printf("%d ",j);
			puts("1");
		}
		printf("%d %d ",n,n-1);
		for(int j=2;j<n-1;j++)
			printf("%d ",j);
		puts("1");
	}
	return 0;
}