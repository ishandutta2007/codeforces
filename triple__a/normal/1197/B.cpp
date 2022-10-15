#include<bits/stdc++.h>
using namespace std;

const int maxn=2000007;
int a[maxn],cnt,n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (a[i]==n){
			cnt=i;
		}
	}
	for (int i=1;i<cnt;++i){
		if (a[i+1]<a[i]){
			printf("no");
			return 0;
		}
	}
	for (int i=n;i>cnt;--i){
		if (a[i]>a[i-1]){
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}