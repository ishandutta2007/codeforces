#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n;
ar<int, 2> a[mxN];

void mp(ar<int, 4> &a) {
	if(a[2]<a[0]) {
		a[3]-=(a[0]-a[2]);
		a[2]=a[0];
	}
	if(a[2]>a[1]) {
		a[3]-=(a[2]-a[1]);
		a[2]=a[1];
	}
}

ar<int, 4> mrg(ar<int, 4> a, ar<int, 4> b) {
	a[0]=b[0]=max(a[0], b[0]);
	a[1]=b[1]=min(a[1], b[1]);
	if(a[0]>a[1])
		return {1};
	mp(a);
	mp(b);
	if(a[2]>b[2])
		swap(a, b);
	if(b[3]-(b[2]-a[2])>=a[3])
		return a;
	if(b[3]<=a[3]-(b[2]-a[2]))
		return b;
	int d=(a[3]-(b[3]-(b[2]-a[2])))/2;
	a[2]+=d;
	a[3]-=d;
	return a;
}

ar<int, 3> chk(int x) {
	ar<int, 4> up{a[0][0]-x, a[0][0]+x, a[0][0], a[0][1]+2*x};
	ar<int, 4> lo{a[0][0]-x, a[0][0]+x, a[0][0], -(a[0][1]-2*x)};
	for(int i=1; i<n; ++i) {
		up=mrg(up, {a[i][0]-x, a[i][0]+x, a[i][0], a[i][1]+2*x});
		lo=mrg(lo, {a[i][0]-x, a[i][0]+x, a[i][0], -(a[i][1]-2*x)});
	}
	lo[3]=-lo[3];
	//if(x==15)
		//cout << up[0] << " " << up[1] << " " << up[2] << " " << up[3] << endl;
	//if(x==15)
		//cout << lo[0] << " " << lo[1] << " " << lo[2] << " " << lo[3] << endl;
	if(up[0]<=up[1]&&lo[0]<=up[2]&&up[2]<=lo[1]&&up[3]-abs(up[2]-lo[2])>=lo[3]) {
		//if(x==1)
			//cout << up[2] << " " << up[3] << endl;
		return {x, (up[2]+up[3])/2, (up[3]-up[2])/2};
	}
	return {-1};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for(char c : s)
			++a[i][c=='N'];
		tie(a[i][0], a[i][1])=make_pair(a[i][0]-a[i][1], a[i][0]+a[i][1]);
	}
	int lb=0, rb=5e5;
	ar<int, 3> ans;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		//cout << mb << endl;
		ar<int, 3> a2=chk(mb);
		if(~a2[0]) {
			rb=mb;
			ans=a2;
		} else
			lb=mb+1;
	}
	cout << ans[0] << "\n";
	//cout << ans[1] << " " << ans[2] << endl;
	for(int i=0; i<ans[1]; ++i)
		cout << 'B';
	for(int i=0; i<ans[2]; ++i)
		cout << 'N';
}