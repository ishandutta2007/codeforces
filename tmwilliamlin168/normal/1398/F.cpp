#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, prv[mxN+1][2], a[mxN+1][2];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	prv[0][0]=prv[0][1]=-1;
	for(int i=0; i<n; ++i) {
		prv[i+1][0]=prv[i][0];
		prv[i+1][1]=prv[i][1];
		a[i+1][0]=a[i][0];
		a[i+1][1]=a[i][1];
		if(s[i]=='?')
			continue;
		prv[i+1][s[i]&1]=i;
		++a[i+1][s[i]&1];
	}
	for(int x=1; x<=n; ++x) {
		int s=0, c=0;
		while(s+x<=n) {
			if(a[s+x][0]-a[s][0]==0) {
				s+=x;
				++c;
				continue;
			}
			if(a[s+x][1]-a[s][1]==0) {
				s+=x;
				++c;
				continue;
			}
			int b=prv[s+x][1]>prv[s+x][0];
			s=prv[s+x][b^1]+1;
		}
		cout << c << " ";
	}
}