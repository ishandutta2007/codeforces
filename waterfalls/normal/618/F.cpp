#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[1000013], b[1000013];
int has[1000013];

int i,j,loc,loc2;

void go(bool rev) {
	if (!rev) {
		printf("%d\n",i-loc);
		for (int k=loc+1;k<=i;k++) printf("%d ",k);
		printf("\n");
	} else {
		loc2 = upper_bound(b,b+n+1,a[loc])-b-1;
		printf("%d\n",j-loc2);
		for (int k=loc2+1;k<=j;k++) printf("%d ",k);
		printf("\n");
	}
}

int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	for (i=1;i<=n;i++) {
		scanf("%lld",&b[i]);
		b[i]+=b[i-1];
	}
	bool rev = 0;
	if (b[n]>a[n]) {
		swap(a,b);
		rev = 1;
	}
	for (i=0;i<=n;i++) {
		j = upper_bound(b,b+n+1,a[i])-b-1;
		if (has[a[i]-b[j]]) {
			loc = has[a[i]-b[j]]-1;
			go(rev);
			go(!rev);
			break;
		}
		has[a[i]-b[j]] = i+1;
	}

	return 0;
}