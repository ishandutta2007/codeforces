#include <iostream>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

int a[1005],b[1005];
int main() {
	int n, m;
	cin >> n >> m;
	m -= 1;
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<n;++i) cin >> b[i];
	if(a[0]==0 || (a[m]==0&&b[m]==0)) cout << "NO\n";
	else if(a[m]==1) cout << "YES\n";
	else {
		int flag = 1;
		for(int i=m;i<n;++i) {
			if(a[i]&&b[i]) {
				flag = 0;
				cout << "YES\n";
				break;
			}
		}
		if(flag)  cout << "NO\n";
	}
}