#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int n;
char str[1000100];

int main() {
	scanf("%d",&n);
	scanf("%s",str);
	int p = 0, ans = 0;
	for (int i=0;i<n;i++) {
		int v = (str[i]=='('?1:-1);
		if (p+v<0||(p+v==0&&p<0)) ans++;
		p += v;
		if (i==n-1&&p!=0) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",ans);

	return 0;
}