#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return a==0 ? b : gcd(b%a,a); }

int n;
multiset<int> has;
int a[513];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n*n;i++) {
		int g;
		scanf("%d",&g);
		has.insert(g);
	}
	for (int i=0;i<n;i++) {
		a[i] = *has.rbegin();
		has.erase(has.find(a[i]));
		for (int j=0;j<i;j++) {
			int res = gcd(a[i],a[j]);
			for (int d=0;d<2;d++) has.erase(has.find(res));
		}
	}
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");

	return 0;
}