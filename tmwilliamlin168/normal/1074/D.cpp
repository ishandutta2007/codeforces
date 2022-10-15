#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int q, lst, p[2*mxN*60], a[2*mxN*60], qt, l, r, x;
map<int, int> mp;

int gi(int x) {
	if(mp.find(x)==mp.end())
		mp.insert({x, mp.size()});
	return mp[x];
}

int find(int x) {
	return x==p[x]?x:(p[x]=find(p[x]));
}

void join(int x, int y) {
	x=find(x);
	y=find(y);
//	cout << "j" << x << " " << y << endl;
	if(a[x]<a[y])
		p[x]=y;
	else
		p[y]=x;
	a[x]+=a[x]==a[y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<2*mxN*60; ++i)
		p[i]=i;
	cin >> q;
	while(q--) {
//		lst=0;
		cin >> qt >> l >> r, l^=lst, r^=lst;
		if(l>r)
			swap(l, r);
//		cout << l << " " << r << "\n";
		++r;
		l=gi(l), r=gi(r);
//		cout << l << " " << r << endl;
		if(qt==1) {
			cin >> x, x^=lst;
			if(find(l*60)==find(r*60)||find(l*60)==find(r*60+1))
				continue;
//			cout << "upd " << l << " " << r << endl;
			for(int i=0; i<30; ++i)
				for(int j=0; j<2; ++j)
					join(l*60+i*2+j, r*60+i*2+(x>>i&1^j));
//			cout << find(l*60) << " " << find(r*60) << endl;
		} else {
			if(find(l*60)!=find(r*60)&&find(l*60)!=find(r*60+1)) {
				cout << "-1\n";
				lst=1;
				continue;
			}
			lst=0;
			for(int i=0; i<30; ++i)
				lst^=(find(l*60+i*2)!=find(r*60+i*2))<<i;
			cout << lst << "\n";
		}
	}
}