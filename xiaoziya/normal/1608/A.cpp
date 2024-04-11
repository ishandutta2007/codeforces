#include<stdio.h>
#include<iostream>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			printf("%d%c",i+1,i==n? '\n':' ');
	}
	return 0;
}