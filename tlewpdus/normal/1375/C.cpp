#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
int arr[300100];

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&arr[i]);
		if (arr[0]>arr[n-1]) puts("NO");
		else puts("YES");
	}

	return 0;
}