#include <bits/stdc++.h>
using namespace std;

vector<int> bp, bq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int lb=1, rb=6.4e4;
	while(lb<=rb) {
		int mb=(lb+rb)/2, ca=a, cb=b;
		vector<int> p, q;
		bool tm=0;
		for(int i=mb; i; --i) {
			if(ca>=i) {
				p.push_back(i);
				ca-=i;
			} else if(cb>=i) {
				q.push_back(i);
				cb-=i;
			} else
				tm=1;
		}
		if(tm)
			rb=mb-1;
		else
			lb=mb+1;
		if(p.size()+q.size()>bp.size()+bq.size()) {
			bp=p;
			bq=q;
		}
	}
	cout << bp.size() << "\n";
	for(int pi : bp)
		cout << pi << " ";
	cout << "\n" << bq.size() << "\n";
	for(int qi : bq)
		cout << qi << " ";
}