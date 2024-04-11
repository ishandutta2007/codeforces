#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test_case;
void solve_componenent() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	// claim: if a[n-1] > a[0]+a[1] works
	// otherwise 
	// lets call the difference d (a[n-1]-a[1]-a[0]) -> we keep going and eventually we decrease this difference
	
	int i=0,j=n-2;
	ll d=-a[n-1];
	while(i<j) {
		d+=a[i]-a[j];
		if(d>0) {
			puts("YES");
			return;
		}
		i++,j--;
	}
	puts("NO");
}
int main() {
	scanf("%d", &test_case);

	while(test_case--) {
		solve_componenent();
	}
}