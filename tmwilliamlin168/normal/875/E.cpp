#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	int *x = new int[n];
	for(int i=0; i<n; ++i)
		cin >> x[i];
	int l=abs(s1-s2), r=(int)1e9, ans=r;
	while(l<=r) {
		int m=(l+r)/2;
		bool works=1;
		int l2=0, r2=(int)1e9;
		for(int i=n-1; i>=0; --i) {
			if(x[i]<l2||x[i]>r2) {
				l2=max(x[i]-m, l2);
				r2=min(x[i]+m, r2);
				if(l2>r2) {
					works=0;
					break;
				}
			} else {
				l2=x[i]-m;
				r2=x[i]+m;
			}
		}
		works&=s1>=l2&&s1<=r2||s2>=l2&&s2<=r2;
		if(works) {
			ans=m;
			r=m-1;
		} else
			l=m+1;
	}
	cout << ans;
}