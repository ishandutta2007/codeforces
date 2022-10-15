#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
template<typename T> struct cp {
	T x, y;
	cp<T> operator+(const cp &o) const {
		return {x+o.x, y+o.y};
	}
	cp<T> operator*(const cp &o) const {
		return {x*o.x-y*o.y, x*o.y+y*o.x};
	}
};
template<typename T> struct fft {
	static const int mxN=1<<19;
	cp<T> rt[mxN];
	void fi(int n) {
		T PI=acos((T)-1);
		for(int i=0; i<n/2; ++i) {
			T an=2*PI*i/n;
			rt[i+n/2]={cos(an), sin(an)};
		}
		for(int i=n/2; --i; )
			rt[i]=rt[2*i];
	}
	void ac(vector<cp<T>> &a) {
		int n=a.size();
		for(int i=0, j=0; i<n; ++i) {
			if(i>j)
				swap(a[i], a[j]);
			for(int k=n/2; (j^=k)<k; k/=2);
		}
		for(int st=1; 2*st<=n; st*=2) {
			for(int i=0; i<n; i+=2*st) {
				for(int j=i; j<i+st; ++j) {
					cp<T> z=rt[j-i+st]*a[j+st];
					a[j+st]=a[j]+cp<T>{-1, 0}*z;
					a[j]=a[j]+z;
				}
			}
		}
	}
	void mul(vector<cp<T>> &g, vector<cp<T>> &h) {
		int n=g.size();
		ac(g);
		for(int i=0; i<n; ++i) {
			int j=(n-i)&(n-1);
			cp<T> g2=g[i]*g[i];
			g2.x=-g2.x;
			h[i]=(g[j]*g[j]+g2)*cp<T>{(T)0, (T)-1/4/n};
		}
		ac(h);
	}
};
fft<long double> f;
vector<cp<long double>> c1(1<<19), c2(1<<19);
int c[1000001];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, x, y;
	cin >> n >> x >> y;
	for(int i=0; i<=n; ++i) {
		int b;
		cin >> b;
		++c1[b].x;
		++c1[x-b].y;
	}
	f.fi(1<<19);
	f.mul(c1, c2);
	for(int i=x+1; i<=2*x; ++i) {
		c[i-x+y]=round(c2[i].x)>0?i-x:0;
	}
	for(int i=1; i<=1e6; ++i)
		for(int j=i; (j+=i)<=1e6; )
			c[j]=max(c[j], c[i]);
	int q;
	cin >> q;
	while(q--) {
		int l;
		cin >> l;
		int a=(c[l/2]+y)*2;
		cout << (c[l/2]?a:-1) << " ";
	}
}