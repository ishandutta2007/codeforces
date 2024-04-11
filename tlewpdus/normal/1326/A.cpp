#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if (n==1) {
			puts("-1");
		}
		else {
			printf("5");
			for (int i=0;i<n-1;i++) printf("9");
			puts("");
		}
	}

	return 0;
}