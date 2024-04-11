#include<bits/stdc++.h>
#define ll long long
#define N 100005

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y<x)
			printf("%d\n",x+y);
		else{
			int a=y/x;
			printf("%d\n",a*x+(y-a*x)/2);
		}
	}
}