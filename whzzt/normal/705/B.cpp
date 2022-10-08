#include"bits/stdc++.h"
using namespace std;

long long sum;
int n,a;

int main(){
	scanf("%d",&n);int i;
	for(i=1;i<=n;i++){
		scanf("%d",&a);sum+=a-1;
		if(sum%2==0)puts("2");
		else puts("1");
	}
	return 0;
}