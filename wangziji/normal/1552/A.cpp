#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string a,b;
		cin >> a;
		b=a;
	sort(b.begin(),b.end());
	int ans=0;
	for(int i=0;i<a.size();i++)
		ans+=a[i]!=b[i];
	cout << ans << "\n";
	}
	return 0;
}