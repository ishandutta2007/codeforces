#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
bool b[1000];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ar<int, 2> k={0, 1};
	for(int i=2; i<=n; ++i)
		k=max(ar<int, 2>{(i-1)*(n/i-1)+((n-1)%i==i-1?0:(n-1)%i), i}, k);
	for(int i=0; i<n/k[1]; ++i)
		for(int j=0; j<k[1]-1; ++j)
			v.push_back(i*k[1]+j);
	for(int i=n/k[1]*k[1]; i<n-1; ++i)
		v.push_back(i);
	int n1=0;
	while(n1<k[0]) {
		vector<int> w;
		for(int vi : v)
			if(!b[vi]) {
				++n1;
				b[vi]=1;
				w.push_back(vi);
			}
		int l=w.size();
		cout << l << "\n";
		for(int wi : w)
			cout << wi+1 << " ";
		cout << endl;
		int x;
		cin >> x, --x;
		for(int i=0; i<l; ++i) {
			n1-=b[(x+i)%n];
			b[(x+i)%n]=0;
		}
	}
	cout << 0 << endl;
}