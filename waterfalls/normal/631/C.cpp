#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200013];
int type[200013], len[200013];
int high[200013];
int res[200013];
multiset<int> has;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d%d",&type[i],&len[i]);
	for (int i=m;i>0;i--) high[i] = max(high[i+1],len[i]);
	for (int i=high[1]+1;i<=n;i++) res[i] = a[i];
	for (int i=1;i<=high[1];i++) has.insert(a[i]);
	int dir = 1;
	int last = high[1];
	for (int i=1;i<=m+1;i++) {
		if (len[i]==high[i]) {
			while (last>len[i]) {
				if (dir==1) {
					res[last--] = *has.rbegin();
					has.erase(--has.end());
				} else {
					res[last--] = *has.begin();
					has.erase(has.begin());
				}
			}
			dir = type[i];
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",res[i]);
	printf("\n");

    return 0;
}