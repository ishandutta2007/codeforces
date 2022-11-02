#include <stdio.h>
#include <algorithm>
int a,b,c,d,n,t[111],x,y;
char r[111][111],q;
bool O;
int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	O=d>b;
	if (O){std::swap(a,c);std::swap(b,d);}
	for(int i=0;i<n;i++)scanf("%d",&t[i]);
	for(int i=0;i<b;i++)for(int j=0;j<a+c;j++)r[i][j]='.';
	y=d%2?a+c-1:0;q='a';
	for (int i=0,j=0;j<n;i++){
		r[x][y]=q;t[j]--;
		if (!t[j]){j++;q++;}
		if ((x%2)^(d%2)){if(!y)x++;else y--;}
		else{if(y==a+c-1||(x>=d&&y==a-1))x++;else y++;}
	}
	puts("YES");
	for (int i=0;i<b;i++){
		for (int j=0;j<a+c;j++)printf("%c",O?r[i][a+c-j-1]:r[i][j]);
		puts("");
	}
}