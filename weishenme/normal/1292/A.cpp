#include<bits/stdc++.h>
using namespace std;
int n,m,a[2][200005],x,y;
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	while (m--){
		scanf("%d%d",&x,&y);
		x-=1;
		cnt-=(a[x][y]&a[x^1][y])+(a[x][y]&a[x^1][y-1])+(a[x][y]&a[x^1][y+1]);
		a[x][y]^=1;
		cnt+=(a[x][y]&a[x^1][y])+(a[x][y]&a[x^1][y-1])+(a[x][y]&a[x^1][y+1]);
		if (cnt)puts("No");
		else puts("Yes");
	}
}