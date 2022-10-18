#include<bits/stdc++.h>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n,r1,c1,r2,c2,r3,c3,x,y;
		scanf("%d",&n);
		scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3);
		scanf("%d%d",&x,&y);
		int r=r1==r2?r1:r1==r3?r1:r2;
		int c=c1==c2?c1:c1==c3?c1:c2;
		if(r==1&&c==1)
			puts(x==1||y==1?"YES":"NO");
		else if(r==1&&c==n)
			puts(x==1||y==n?"YES":"NO");
		else if(r==n&&c==1)
			puts(x==n||y==1?"YES":"NO");
		else if(r==n&&c==n)
			puts(x==n||y==n?"YES":"NO");
		else if((abs(r-x)+abs(c-y))%2==1)
			puts("YES");
		else if(abs(r-x)%2==1||abs(c-y)%2==1)
			puts("NO");
		else
			puts("YES");
	}
}