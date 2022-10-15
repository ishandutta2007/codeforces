#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
int n;
int a[maxn];

bool ck(){
	long long sum=0;
	for (int i=1;i<n;++i){
		sum+=a[i];
	}
	if (sum<a[n]||(sum+a[n])%2==1) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if (ck()){
		printf("YES");
	}
	else{
		printf("NO");
	}
}