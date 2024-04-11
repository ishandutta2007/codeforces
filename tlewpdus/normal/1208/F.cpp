#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;

int n;
int arr[1000100];
int cnt[2100000];

void upd(int v, int w) {
	if (cnt[w]==2) return;
	if (!v) {
		cnt[w]++;
		//printf(" %d!\n",w);
		return;
	}
	int t = v&-v;
	upd(v^t,w^t);
	upd(v^t,w);
}

void upd(int v) {
	upd(v,v);
}

bool can(int mask) {
	memset(cnt,0,sizeof(cnt));
	//printf("-> %d!\n",arr[n-1]);
	upd(arr[n-1]);
	//printf("-> %d!\n",arr[n-2]);
	upd(arr[n-2]);
	for (int i=n-3;i>=0;i--) {
		if (cnt[mask&~arr[i]]==2) return 1;
		//printf("-> %d!\n",arr[i]);
		upd(arr[i]);
	}
	return 0;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	int ans = 0;
	for (int i=(1<<20);i;i>>=1) {
		if (can(ans|i)) {
			ans|=i;
		}
	}
	printf("%d\n",ans);

	return 0;
}