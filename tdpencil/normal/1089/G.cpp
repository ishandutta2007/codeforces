#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while(t--) {
		int k; cin >> k;
		array<int, 7> a,p;
		int tot=0;
		for(int i = 0; i < 7; ++i)
			cin >> a[i], tot+=a[i];
		for(int i = 0; i < 7; ++i)
			if(i==0)
				p[i]=a[i];
			else
				p[i]=p[i-1]+a[i];
		if(k<=tot) {
			int c=1e9;	
			for(int i =0;i<7;i++) {
				int s=0;	
				int cur=i;
				int ans=0;
				while(s < k) {
					s+=a[(cur)%7];
					++ans;	
					++cur;
				}
				c=min(c,ans);
			}
			cout << c << "\n";	
			continue;
		}
		int s=0;
		int ans=1e9;
		for(int i =0;i<7;++i) {
			//cout << "First: " << i+1 << "\n";
			int start=(7-i);
			int left=tot-s;
			int v=k-left;
			int x=(v-1)/tot;
			//cout << x << "\n";
			//cout << v << "\n";
			//cout << left << "\n";
			int cycles=x*7+start;
			//cout << cycles << "\n";	
			v-=x*tot;
			//cout << v << "\n";
			for(int j=0;j<7;j++) {
				if(v<=0)
					break;
				v-=a[j];
				++cycles;
			}
			s+=a[i];
			//cout << cycles << "\n";
			ans=min(ans,cycles);
		}
		cout << ans << "\n";

	}
}