#include<bits/stdc++.h>

using namespace std;

int n,a,b,c,d;

int main(){
	scanf("%d",&n);puts("YES");
	while(n--)scanf("%d%d%d%d",&a,&b,&c,&d),printf("%d\n",(a&1)+(b&1)*2+1);
	return 0;
}