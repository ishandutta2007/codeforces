#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int n;
int arr[400100];
int cnt[34001000];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	int x = 0;
	for (int b=0;b<25;b++) {
		for (int i=0;i<n;i++) cnt[arr[i]&((1<<(b+1))-1)]++;
		{
			int i = 0;
			int s = (1 << b), e = (1<<(b+1))-1;
			int sum = 0;
			ll ans = 0;
			for (int j=s;j<=e;j++) sum += cnt[j];
			while(i<(1<<(b+1))) {
				ans += 1LL*cnt[i]*sum;
				sum += (s?cnt[s-1]:cnt[(1<<(b+1))-1]); s = (s?s-1:(1<<(b+1))-1);
				sum -= cnt[e]; e = (e?e-1:(1<<(b+1))-1);
				i++;
			}
			for (int i=0;i<n;i++) {
				if ((2*arr[i])>>b&1) ans--;
			}
			if (ans/2%2) x |= 1<<b;
		}
		for (int i=0;i<(1<<(b+1));i++) cnt[i] = 0;
	}
	printf("%d\n",x);

	return 0;
}