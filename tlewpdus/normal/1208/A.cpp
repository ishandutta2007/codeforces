#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int t;
int a, b, c;

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&a,&b,&c);
		if (c%3==2) printf("%d\n",a^b);
		else if (c%3==1) printf("%d\n",b);
		else printf("%d\n",a);
	}

	return 0;
}