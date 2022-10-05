#include <bits/stdc++.h>
using namespace std;
int a[4];
int main(){
	for(int i=0;i<4;i++)	scanf("%d",&a[i]);
	sort(a,a+4);
	printf("%d %d %d\n",a[3]-a[2],a[3]-a[1],a[3]-a[0]);
}