#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 200006; 

int n, q; 
ll s[maxn]; 
int l[maxn], r[maxn]; 
int num; 
ll totlen; 

void link(int x) {
	int ll = l[x]; 
	int rr = r[x+1]; 
	r[ll] = rr; 
	l[rr] = ll;
	num--; 
	totlen += s[x+1]-s[x];  
}

vector<pair<ll,int>> d;
vector<pair<ll,int>> que;
ll ans[maxn];  
 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%lld", &s[i] ); 
		l[i] = i; r[i] = i; 
	}
	totlen = 0; num = n; 
	sort(s+1, s+n+1); 
	for (int i = 1; i < n; ++i) 
		d.pb({s[i+1]-s[i],i}); 
	sort(d.begin(), d.end()); 
	reverse(d.begin(), d.end()); 
	
	scanf( "%d", &q);  
	for (int i = 1; i <= q; ++i) {
		ll l, r; 
		scanf( "%lld%lld", &l, &r ); 
		que.pb({r-l+1,i});
	}
	sort(que.begin(), que.end()); 
	
	for (auto Q : que) {
		while (!d.empty() && d.back().fir <= Q.fir)  {
			link(d.back().sec); 
			d.pop_back();
		}
		ans[Q.sec] = ll(num)*Q.fir+totlen; 
	}
	for (int i = 1; i <= q; ++i) printf( "%lld ", ans[i] ); 
	puts( "" ); 
}