#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=10007;
int n;
int a[maxn];

bool check(){
	for (int i=1;i<2*n;++i){
		if (a[i]!=a[0]){
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<2*n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+2*n);
	if (check()){
		for (int i=0;i<2*n;++i){
			printf("%d ",a[i]);
		}
	}
	else{
		printf("-1");
	}
	return 0;
}