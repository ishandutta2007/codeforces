#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int x,k;
		scanf("%d%d",&x,&k);
		for (;k>3;k--,x--,printf("1 "));
		if (x%3==0) printf("%d %d %d\n",x/3,x/3,x/3);
		else
			for (int i=1;i<=x;i<<=1)
				if ((x/i)%2==1||(i*2==x)){
					printf("%d %d %d\n",i,(x-i)/2,(x-i)/2);
					break;
				}
	}
}