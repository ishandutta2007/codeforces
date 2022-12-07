#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int n, id[105], e = 233, A, B;
vector<int> h;

int ask1(int a, int b) {
	A--;
	assert(A>=0);
	cout << 1 << " " << a << " " << b << endl;
	cin >> a;
	assert(a!=-1);
	return a;
}

int ask2(int a, vector<int> x) {
	B--;
	assert(B>=0);
	cout << 2 << " " << a << " " << x.size() << " ";
	for (auto z : x)
		cout << z << " ";
	cout << endl;
	cin >> a;
	assert(a!=-1);
	return a;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		h = {0};
		cin >> n;
		A=9*n;
		B=2*n;
		rep(i,1,n-1) {
			if (ask1(h.back(), i)) {
				h.push_back(i);
				continue;
			}
			if (ask1(i, h[0])) {
				h.insert(h.begin(), i);
				continue;
			}
			int l=1,r=h.size()-1;
			while(l<r){
				int m=(l+r)/2;
				if(ask1(i, h[m])) 
					r=m;
				else
					l=m+1;
			}
			h.insert(h.begin() + r, i);
		}
		//~ cout<<"H";
		//~ for(auto x:h)
			//~ cout<<x<<" "; cout <<endl;
		iota(id, id+n, 0);
		for(int i=n-1; i>=0; i--) {
			while (1) {
				int r = i;
				while (r>=0 && id[r] == id[i]) r--;
				if(r<0)break;
				assert(r<i);
				vector<int> x;
				rep(j,0,r) x.push_back(h[j]);
				if(ask2(h[i],x)) {
					for(int k=r; k>=0; k--) {
						if (ask1(h[i], h[k])) {
							int L,R;
							rep(g,0,n-1)
								if(id[g] == id[k]) {
									L = g;
									break;
								}
							rep(g,0,n-1)
								if(id[g] == id[i])
									R = g;
							++e;
							rep(g,L,R)
								id[g] = e;
							break;
						}
					}
				}
				else break;
			}
		}
		cout << 3 << endl;
		rep(i,0,n-1) {
			rep(j,0,n-1) {
				auto fuck = [&](int x) {
					rep(f,0,n-1)
						if(h[f] == x)
							return f;
				};
				if (id[fuck(i)] == id[fuck(j)])
					cout << 1;
				else
					cout << (fuck(i) < fuck(j));
			}
			cout<<endl;
		}
		int q;
		cin>>q;
		assert(q==1);
	}
	return 0;
}