#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define ll long long
void dbg(vt<int> &a) {for(auto &edge: a) cout << edge << " ";}
int main() {
	int n; cin >> n;

	vt<int> a(n);
	for(int i=0; i < n; i++)
		cin >> a[i];
	int f = *max_element(a.begin(), a.end());
	int s = *min_element(a.begin(), a.end());
	int pt1=0,pt2=0;
	int ans=0;
	for(int i=0; i < n; i++)
		if(a[i] == f) {
			pt1 = i;
			break;
		}
	for(int i=0; i < n; i++)
		if(a[i] == s)
			pt2 = i;
	if(pt1 > pt2) ans--;
	for(int i=pt2+1; i < n; i++)
		swap(a[i], a[pt1]), ++ans;
	for(int i=pt1-1; ~i; --i)
		swap(a[i], a[pt2]), ++ans;


	cout << ans << "\n";
	
}