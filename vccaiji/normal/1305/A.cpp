#include<bits/stdc++.h>
using namespace std;
int a[110000],b[110000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}