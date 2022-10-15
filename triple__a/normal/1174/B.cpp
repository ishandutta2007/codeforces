#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100007;

int n,a[maxn];

bool check(){
	for (int i=1;i<n;++i){
		if (a[i]%2!=a[0]%2){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	if (check()){
		sort(a,a+n);
	}
	for (int i=0;i<n;++i){
			printf("%d ",a[i]);
	}
	return 0;
}