#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, r;
	ll k;
	cin >> n >> m >> r >> k;
	ll *row = new ll[n], *col = new ll[m];
	for(int i=0; i<n; ++i)
		row[i]=min(min(i+1, n-i), min(r, n-r+1));
	for(int i=0; i<m; ++i)	
		col[i]=min(min(i+1, m-i), min(r, m-r+1));
	ll lb=1, rb=(ll)1e10;
	long double ans;
	while(lb<=rb) {
		ll mb=(lb+rb)/2;
		ll cnt=0, sum=0, _min=LLONG_MAX;
		for(int i=0; i<n; ++i) {
			ll require=(mb-1)/row[i]+1;
			if(require>min(r, m-r+1))
				continue;
			ll ccnt=m-2*(require-1);
			cnt+=ccnt;
			sum+=row[i]*require*ccnt;
			sum+=(ccnt-1)/2*(ccnt/2)*row[i];
			ll dcnt=m-2*(min(r, m-r+1)-1);
			if(dcnt>0)
				sum-=(dcnt-1)/2*(dcnt/2)*row[i];
			_min=min(require*row[i], _min);
			//if(mb==18)
			//	cout << sum << " " << ccnt << " " << dcnt << endl;
		}
		//cout << mb << " " << cnt << " " << sum << " " << _min << endl;
		if(cnt>=k) {
			sum-=(cnt-k)*_min;
			ans=sum/((n-r+1.0)*(m-r+1));
			lb=mb+1;
		} else
			rb=mb-1;
	}
	cout << fixed << setprecision(15) << ans;
}