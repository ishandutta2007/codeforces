#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const double eps = 1e-9;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

char s[MAXN];
int sum[MAXN];

int main(){
	int n, k;
	scanf("%d%d%s", &n, &k, s+1);
	k++;
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + (s[i] == '0');
	sum[n+1] = sum[n];

//	for(int i = 1; i <= n; i++)
//		cout<<sum[i]<<' '; cout<<endl;
	int ans = n + 1;
	for(int i = 1; i <= n; i++)
		if (s[i] == '0'){
		int high = n + 1, low = 0, mid;
		while(low + 1 < high){
			mid = (low + high) >> 1;
			if (sum[min(i + mid, n)] - sum[max(0, i - mid - 1)] >= k)
				high = mid;
			else
				low = mid;
		}
		ans = min(ans, high);
	}
	cout<<ans<<endl;
	return 0;
}