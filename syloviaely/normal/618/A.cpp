#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int n; scanf("%d",&n);
	for (int i=20;i>=0;i--)
		if (n&(1<<i)) printf("%d ",i+1);
	printf("\n");
}