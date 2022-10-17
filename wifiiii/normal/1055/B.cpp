#include <iostream>
#include <stdio.h>
typedef long long ll;
using namespace std;
int a[100005],b[100005];
int main() {
	//freopen("in.txt","r",stdin);
	int n,m,l,cnt=0;
	cin >> n >> m >> l;
	for(int i=0;i<n;++i) {
		cin >> a[i];
		if(a[i] <= l) b[i] = 1;
		else if(a[i] > l && (i==0 || b[i-1] == 1)) cnt += 1;
	}
	int q;
	while(m--) {
		cin >> q;
		if(q==0) {
			cout << cnt << endl;
		} else {
			int p,d;
			cin >> p >> d;
			p -= 1;
			a[p] += d;
			if(a[p] > l && b[p]) {
				if((p==0 || b[p-1]) && (p==n-1 || b[p+1])) cnt += 1;
				else if(p==0 || p==n-1 || b[p-1] || b[p+1]);
				else if(b[p-1]==0&&b[p+1]==0) cnt -= 1;
				else cnt += 1;
				b[p] = 0;
			}
		}
	}
	
}