#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,e,f;
int w1,w2,w3;

int main() {
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	w1 = 0, w2 = 1, w3 = 2;
	int tot = a*b+c*d+e*f;
	int side = 0;
	for (int i=1;i<1000;i++) if (tot==i*i) side = i;
	if (!side) return printf("-1\n"), 0;
	if (b==side) swap(a,b);
	if (d==side) swap(c,d);
	if (f==side) swap(e,f);
	if (a==side);
	else if (c==side) swap(a,c), swap(b,d), swap(w1,w2);
	else if (e==side) swap(a,e), swap(b,f), swap(w1,w3);
	if (a!=side) return printf("-1\n"), 0;
	if (c==side || e==side) {
		if ((c==side)+(e==side)==1 || b+d+f!=side) return printf("-1\n"), 0;
		printf("%d\n",side);
		for (int i=0;i<b;i++) {
			for (int j=0;j<a;j++) printf("%c",'A'+w1);
			printf("\n");
		}
		for (int i=0;i<d;i++) {
			for (int j=0;j<c;j++) printf("%c",'A'+w2);
			printf("\n");
		}
		for (int i=0;i<f;i++) {
			for (int j=0;j<e;j++) printf("%c",'A'+w3);
			printf("\n");
		}
	} else {
		if (d==side-b) swap(c,d);
		if (f==side-b) swap(e,f);
		if (c!=side-b || e!=side-b || d+f!=side) return printf("-1\n"), 0;
		printf("%d\n",side);
		for (int i=0;i<b;i++) {
			for (int j=0;j<a;j++) printf("%c",'A'+w1);
			printf("\n");
		}
		for (int i=0;i<side-b;i++) {
			for (int j=0;j<d;j++) printf("%c",'A'+w2);
			for (int j=0;j<f;j++) printf("%c",'A'+w3);
			printf("\n");
		}
	}

	return 0;
}