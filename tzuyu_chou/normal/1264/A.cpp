#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MAXN=4e5;
int n, p[MAXN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> p[i];
	}
	vector<int> v;
	for(int i=0, j=0; i<n; i=j) {
		for(; j<n&&p[j]==p[i]; ++j);
		v.push_back(j-i);
		//cout << v.back() << endl;
	}
	int s1=0, s2=0, s3=0;
	int i=0, j=0, k=0;
	int a1=0, a2=0, a3=0;
	while(1) {
		s1+=v[i];
		s2-=v[i];
		++i;
		while(s2<=s1&&j<v.size()) {
			s2+=v[j];
			s3-=v[j];
			++j;
		}
		if(s2<=s1)
			break;
		while(s3<=s1&&k<v.size()) {
			s3+=v[k];
			++k;
		}
		if(s3<=s1)
			break;
		if(2*(s1+s2+s3)>n)
			break;
		while(k<v.size()&&2*(s1+s2+s3+v[k])<=n) {
			s3+=v[k];
			++k;
		}
		a1=s1;
		a2=s2;
		a3=s3;
		break;
	}
	cout << a1 << " " << a2 << " " << a3 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}