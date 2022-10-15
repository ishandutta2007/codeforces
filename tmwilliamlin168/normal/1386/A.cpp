#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

bool qry(ll a) {
	++a;
	assert(1<=a&&a<=n);
	int b;
	cout << "? " << a << endl;
	cin >> b;
	return b;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int a=0;
		while((1ll<<a+2)<=n)
			++a;
		ll m=n-(1ll<<a+1), s=0;
		for(int i=a-1; i>=0; i-=2)
			s+=1ll<<i;
		if(m<=1) {
			bool l=0;
			ll x=0;
			if(m&&a%2==0)
				++s;
			qry(s);
			for(int i=a; i>=0; --i) {
				s=l?s-x-(1ll<<i):s+x+(1ll<<i);
				if(!qry(s))
					x+=1ll<<i;
				l=!l;
			}
			if(m&&x==n-2) {
				s=l?0:n-1;
				if(!qry(s))
					x=n-1;
			}
			cout << "= " << x+1 << endl;
		} else {
			if(n<=64) {
				//i need this to pass idk why
				qry(0);
				bool l=0;
				ll s=0, x=n-1;
				while(x) {
					s=l?s-x:s+x;
					if(!qry(s))
						break;
					--x;
					l=!l;
				}
				cout << "= " << x+1 << endl;
				continue;
			}
			ll t=s;
			bool l=0;
			for(int i=a; i>=0; --i) {
				t=l?t-(1ll<<i):t+(1ll<<i);
				l=!l;
			}
			qry(t);
			if(qry(t+m)) {
				if(m<=(1ll<<a)) {
					--a;
					s=0;
					for(int i=a-1; i>=0; i-=2)
						s+=1ll<<i;
					l=0;
					ll x=0;
					qry(s);
					for(int i=a; i>=0; --i) {
						s=l?s-x-(1ll<<i):s+x+(1ll<<i);
						if(!qry(s))
							x+=1ll<<i;
						l=!l;
					}
					cout << "= " << x+1 << endl;
				} else {
					qry(s);
					l=0;
					ll x=0;
					for(int i=a; i>=0; --i) {
						s=l?s-x-(1ll<<i):s+x+(1ll<<i);
						if(s==t) {
							assert(!i);
							qry(t+m-1-x-1);
							s=t+m-1;
						}
						if(!qry(s))
							x+=1ll<<i;
						l=!l;
					}
					cout << "= " << x+1 << endl;
				}
			} else {
				qry(s);
				l=0;
				ll x=m;
				for(int i=a; i>=0; --i) {
					s=l?s-x-(1ll<<i):s+x+(1ll<<i);
					if(s==t) {
						assert(!i);
						qry(t+m-1-x-1);
						s=t+m-1;
					}
					if(s==t+m) {
						assert(!i);
						qry(t+m-1-x-1);
						s=t+m-1;
					}
					if(!qry(s))
						x+=1ll<<i;
					l=!l;
				}
				cout << "= " << x+1 << endl;
			}
		}
	}
}