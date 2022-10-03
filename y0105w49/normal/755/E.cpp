#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef long long ll;
#define fi first
#define se second
#define pb push_back



bool _main() {
	int n,k; cin>>n>>k;
	if(k>3) return 0;
	if(k==1) return 0;
	if(k==3 && n>=4) {
		int C=n-3;
		int m=C+C+1;
		printf("%d\n",m);
		printf("1 2\n");
		for(int i=4;i<=n;i++) printf("2 %d\n",i);
		for(int i=4;i<=n;i++) printf("3 %d\n",i);
		return 1;
	}
	if(k==3) return 0;
	assert(k==2);
	if(k==2 && n>=5) {
		int C=n-4;
		int m=C+C+3;
		printf("%d\n",m);
		printf("1 2\n2 3\n3 4\n");
		for(int i=5;i<=n;i++) printf("1 %d\n",i);
		for(int i=5;i<=n;i++) printf("4 %d\n",i);
		return 1;
	}
	if(k==2 && n==2) return 0;
	if(k==2 && n==3) return 0;
	if(k==2 && n==4) return 0;
	assert(0);
}

int main() {
	if(!_main()) printf("-1\n");
}