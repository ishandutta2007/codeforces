#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,lli>;

int n;
pii a[100],b[100];

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i].fi),a[i].se=i;
		for(int i=0;i<n;i++) scanf("%d",&b[i].fi),b[i].se=i;
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++) printf("%d ",a[i].fi);
		puts("");
		for(int i=0;i<n;i++) printf("%d ",b[i].fi);
		puts("");
	}
	return 0;
}