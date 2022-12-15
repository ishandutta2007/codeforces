#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, ans;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	for(x=1;x<=10000;x++){
		if(a%x) continue;
		y = a/x;
		if(b%y) continue;
		if(c%x) continue;
		if(c/x==b/y){
			printf("%d\n",4*(x+y+b/y));
			return 0;
		}
	}
	return 0;
}