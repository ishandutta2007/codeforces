#include <bits/stdc++.h>
using namespace std;
void test(){
	int n,a,b,c,d,e,f,x,y;
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	scanf("%d%d",&x,&y);
	const int angx=(a+c+e-(a^c^e))/2,angy=(b+d+f-(b^d^f))/2;
	if(angx==1&&angy==1)
		puts(x==1||y==1?"YES":"NO");
	else
		if(angx==1&&angy==n)
			puts(x==1||y==n?"YES":"NO");
		else
			if(angx==n&&angy==n)
				puts(x==n||y==n?"YES":"NO");
			else
				if(angx==n&&angy==1)
					puts(x==n||y==1?"YES":"NO");
				else
					puts((angx%2!=x%2)&&(angy%2!=y%2)?"NO":"YES");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}