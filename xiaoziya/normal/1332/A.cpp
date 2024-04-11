#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int T,a,b,c,d,x,y,x1,y1,x2,y2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y,&x1,&y1,&x2,&y2);
		x=x-a+b,y=y-c+d;
		if(x1<=x&&x<=x2&&y1<=y&&y<=y2&&(a==0||b==0||x1<x||x<x2)&&(c==0||d==0||y1<y||y<y2))
			puts("Yes");
		else puts("No");
	}
	return 0;
}