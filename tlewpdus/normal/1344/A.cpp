#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
int arr[200100];
int chk[200100];

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&arr[i]);
		for (int i=0;i<n;i++) chk[i] = 0;
		int mang = 0;
		for (int i=0;i<n;i++) {
			int v = i+arr[i];
			int c = (v%n+n)%n;
			if (chk[c]) mang = 1;
			chk[c] = 1;
		}
		puts(mang?"NO":"YES");
	}

	return 0;
}