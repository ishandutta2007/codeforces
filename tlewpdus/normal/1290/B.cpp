#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k;
char str[200100];
int psum[30][200100];

int main() {
	scanf("%s",str+1);
	n = strlen(str+1);
	for (int i=0;i<26;i++) {
		for (int j=1;j<=n;j++) {
			psum[i][j] = psum[i][j-1]+(str[j]=='a'+i);
		}
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int s, e;
		scanf("%d%d",&s,&e);
		int c = 0;
		for (int j=0;j<26;j++) {
			c += (psum[j][e]-psum[j][s-1]>0);
		}
		if (c==1) {
			puts(s==e?"Yes":"No");
		}
		else if (c==2) {
			puts(str[s]==str[e]?"No":"Yes");
		}
		else {
			puts("Yes");
		}
	}

	return 0;
}