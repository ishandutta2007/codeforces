#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,K,d;
int main(){
	scanf("%d%d%d%d",&n,&t,&K,&d);
	int way=(n-1)/K+1;
	int pre=way*t;
	for (int i=1;i<=way;i++){
		int ne=max((way-i)*t,d+t*i);
		if (ne<pre) {printf("YES\n"); return 0;}
	}
	printf("NO\n");
	return 0;
}