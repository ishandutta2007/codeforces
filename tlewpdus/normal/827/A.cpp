#include <bits/stdc++.h>

using namespace std;

int n;
int nxt[2000100];
char str[2000100];
char buf[1000100];
int m;

int fin(int a) {return ((!str[a])?a:nxt[a]=fin(nxt[a]));}

void put(int x) {
	int st = x;
	while(x-st<m) {
		str[x] = buf[x-st];
		x = fin(x);
	}
}

int main() {
	int i, j, k;

	scanf("%d",&n);
	for (i=0;i<=2000010;i++) nxt[i] = i+1;
	for (i=0;i<n;i++) {
		scanf("%s",buf);
		m = strlen(buf);
		scanf("%d",&k);
		for (j=0;j<k;j++) {
			int x;
			scanf("%d",&x); --x;
			put(x);
		}
	}
	for (i=2000010;i>=0;i--) {
		if (str[i]) break;
	}
	int len = i+1;
	for (i=0;i<len;i++) if (!str[i]) str[i] = 'a';
	printf("%s\n",str);

    return 0;
}