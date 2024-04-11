#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int n2=n;
		vector<int> pf;
		for(int i=2; i*i<=n; ++i) {
			if(n%i)
				continue;
			while(n%i==0) {
				n/=i;
				pf.push_back(i);
			}
		}
		if(n>1)
			pf.push_back(n);
		sort(pf.begin(), pf.end());
		int j1=0, j2=pf.size()-1;
		while(j1+1<pf.size()&&pf[j1+1]==pf[0])
			++j1;
		while(j2-1>=0&&pf[j2-1]==pf.back())
			--j2;
		if(j1+1<j2) {
			//3 distinct prime factors
			cout << "YES\n";
			int a=1;
			for(int i=0; i<=j1; ++i)
				a=a*pf[i];
			cout << a << " ";
			a=1;
			for(int i=j1+1; i<j2; ++i)
				a=a*pf[i];
			cout << a << " ";
			a=1;
			for(int i=j2; i<pf.size(); ++i)
				a=a*pf[i];
			cout << a << "\n";
		} else if(j2) {
			//2 distinct prime factors
			if(pf.size()-j2>=3) {
				reverse(pf.begin(), pf.end());
				j1=pf.size()-1-j2;
			}
			if(j1+1>=3) {
				cout << "YES\n";
				cout << pf[0] << " " << pf[1]*pf[2] << " " << n2/pf[0]/pf[1]/pf[2] << "\n";
				continue;
			} else if(j1+1==2&&pf.size()==4) {
				cout << "YES\n";
				cout << pf[0] << " " << pf[3] << " " << pf[1]*pf[2] << "\n";
				continue;
			}
			cout << "NO\n";
		} else {
			//1 factor
			if(pf.size()<6) {
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			cout << pf[0] << " " << pf[1]*pf[2] << " " << n2/pf[0]/pf[1]/pf[2] << "\n";
		}
	}
}