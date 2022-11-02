#include<cstdio>
bool vis[10];
bool check(int x) {
	for(int i=0;i<10;i++) vis[i] = false;
	while( x ) {
		if( vis[x % 10] ) return false;
		vis[x % 10] = true;
		x /= 10;
	}
	return true;
}
int main() {
	int l, r; scanf("%d%d", &l, &r);
	int ans = 0;
	for(int i=l;i<=r;i++)
		if( check(i) ){
			printf("%d\n", i);
			return 0;
			
			}
	printf("-1\n");
}