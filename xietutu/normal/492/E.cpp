#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 1000005;
int n,m,dx,dy,max,pos,a[maxn],b[maxn];
int main() {
	scanf("%d%d%d%d",&n,&m,&dx,&dy);
	int x = 0,y = 0;
	for (int i = 1; i < n; ++i) { 
		x = (x + dx) % n;
		y = (y + dy) % n;
		a[x] = y;
	}
	
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d",&x,&y);
		y = (y - a[x] + n) % n;
		++b[y];
	}
	
	for (int i = 0; i < n; ++i) 
		if (b[i] > max) {
			max = b[i]; pos = i;
		}
	
	printf("%d %d\n",0,pos);
}