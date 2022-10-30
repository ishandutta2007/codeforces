#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[200000];
bool d[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, ans=0;
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for(int i=0; i<n; ++i) {
		for(int j=i-1; j>=0; --j) {
			if(a[j]==a[i])
				break;
			if(!d[j]&&a[i]<=a[j]+k) {
				d[j]=1;
				++ans;
			}
			else
				break;
		}
	}
	cout << n-ans;
}