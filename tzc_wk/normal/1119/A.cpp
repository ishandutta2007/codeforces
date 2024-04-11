#include <bits/stdc++.h>
using namespace std;
int n,c[300001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",c+i);
	int p1=0,p2=n-1;
	while(c[p1]==c[0])	p1++;
	while(c[p2]==c[0])	p2--;
	printf("%d\n",max(n-p1-1,p2));
}