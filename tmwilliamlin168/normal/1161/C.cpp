#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int j=0;
	while(j+1<n&&a[j+1]==a[j])
		++j;
	if(j<n/2)
		cout << "Alice";
	else
		cout << "Bob";
}