#include<cstdio>
long long GetAns(int x) {
	if( x & 1 ) return (x-1)/2-x;
	else return x/2;
}
int main() {
	int q;
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%I64d\n", GetAns(r) - GetAns(l-1));
	}
}