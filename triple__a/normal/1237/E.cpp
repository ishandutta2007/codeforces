#include<bits/stdc++.h>
using namespace std;

int n;

bool ck(int n){
	if (n==1||n==2) return 1;
	bool fg=false;
	int a=4,b=5,u,v;
	while (a<=n){
		if (a==n||b==n) return 1;
		if (fg){
			u=a+b+1,v=2*b+1;
			a=u,b=v;
		}
		else{
			u=2*a+1,v=a+b+1;
			a=u,b=v;
		}
		fg=1-fg;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	printf("%d\n",ck(n));
}