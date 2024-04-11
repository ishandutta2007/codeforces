#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,x;
int a[20];

int decomp(int n){
	memset(a,0,sizeof(a));
	int cnt=0;
	while(n){
		a[cnt++]=(n&1);
		n>>=1; 
	}
	return cnt;
}
int main(){
	scanf("%d%d",&n,&x);
	int l=decomp(x);
	if (l>n){
		printf("%d\n",(1<<n)-1);
		int u=0;
		for (int i=1;i<=(1<<n)-1;++i){
			printf("%d ",u^i);
			u=i; 
		}
	}
	else{
		printf("%d\n",(1<<(n-1))-1);
		int ans=0,u=0;
		for (int i=1;i<=(1<<n)-1;++i){
			int u=decomp(i);
			if (a[l-1]){
				continue;
			}
			printf("%d ",ans^i);
			ans=i;
		}
	}
	return 0;
}