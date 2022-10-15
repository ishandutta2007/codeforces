#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N=50050;

int a[N],n;
int mn=2333333;

int main(){
	
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<mn)mn=a[i];
	}
	for(i=1;i<=n;i++)
		if(a[i]%mn)
			break;
	if(i<=n)
		puts("-1");
	else{
		printf("%d\n%d",2*n-1,a[1]);
		for(i=2;i<=n;i++)
			printf(" %d %d",mn,a[i]);
	}

	return 0;
}