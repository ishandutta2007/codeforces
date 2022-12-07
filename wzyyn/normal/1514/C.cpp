#include<bits/stdc++.h>
using namespace std;

int q[100005],n;
int gcd(int x,int y){
	return y?gcd(y,x%y):x; 
}
int main(){
	scanf("%d",&n);
	int v=1;
	for (int i=1;i<n;i++)
		if (gcd(i,n)==1){
			q[++*q]=i;
			v=1ll*v*i%n;
		}
	if (v!=1) --*q;
	printf("%d\n",*q);
	for (int i=1;i<=*q;i++)
		printf("%d ",q[i]);
}