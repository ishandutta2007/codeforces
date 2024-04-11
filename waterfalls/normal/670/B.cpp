// :'( still mad about dumb stuff
// also who thought k=2e9 was a good idea
#include <bits/stdc++.h>
using namespace std;

int n,k;
int id[100013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&id[i]);
	for (int i=1;i<=n;i++) {
		if (1LL*i*(i+1)/2>=k) {
			printf("%d\n",id[k-1LL*(i-1)*i/2]);
			return 0;
		}
	}

	return 0;
}