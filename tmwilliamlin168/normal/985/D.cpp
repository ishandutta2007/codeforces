#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, H, lb, rb, mb;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> H;
	if(H>=2e9||H*(H+1)/2>=n) {
		lb=1, rb=2e9;
		while(lb<=rb) {
			mb=(lb+rb)/2;
			if(mb*(mb+1)/2>=n)
				rb=mb-1;
			else
				lb=mb+1;
		}
	} else {
		n+=H*(H-1)/2;
		lb=1, rb=3e9;
		while(lb<=rb) {
			mb=(lb+rb)/2;
			if((mb+1)/2*(mb/2+1)>=n)
				rb=mb-1;
			else
				lb=mb+1;
		}
		lb-=H-1;
	}
	cout << lb;
}