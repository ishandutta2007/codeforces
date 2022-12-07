#include<bits/stdc++.h>
using namespace std;
long long x,y,a[10];
int main(){
	scanf("%I64d%I64d",&x,&y);
	a[1]=x; a[2]=y;
	scanf("%I64d",&x);
	a[1]-=2*x;
	scanf("%I64d",&x);
	a[1]-=x; a[2]-=x;
	scanf("%I64d",&x);
	a[2]-=3*x;
	printf("%I64d\n",max(-a[1],0ll)+max(-a[2],0ll));
}