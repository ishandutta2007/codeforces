#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cstring>

using namespace std;

int n,res[100100];

void f1(int val) {
	if(val==0) return;

	int c=1;
	while( (c<<1)<=val ) c<<=1;
	
	for(int i=0;i+c<=val;i++) {
		res[i+c]=c-i-1;
		res[c-i-1]=c+i;
	}
	f1( c-(val-c+1)-1 );
}
void f2(int val) {
	if(val==6) {
		printf("3 6 2 5 1 4 ");
	}
	else if(val==7) {
		printf("5 6 2 7 3 4 1 ");
	}
	else {
		int c=1;
		while( (c<<1)<=val ) c<<=1;
		
		f2(c-1);
		for(int i=c;i<val;i++) printf("%d ",i+1);
		printf("%d ",c);
	}
}

int main() {
	scanf("%d",&n);
	if(n%2) puts("NO");
	else {
		puts("YES");
		f1(n);
		for(int i=1;i<=n;i++) printf("%d ",res[i]);
		puts("");
	}
	
	if(n<=5) puts("NO");
	else {
		int c=1;
		while( (c<<1)<=n ) c<<=1;
		if(n==c) puts("NO");
		else {
			puts("YES");
			f2(n);
		}
	}

	return 0;
}