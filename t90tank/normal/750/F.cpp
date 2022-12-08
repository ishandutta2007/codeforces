#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back 
int a[200]; 
int tot; 
bool v[200]; 
vi e[200]; 
vi E[200]; 
int p[200]; 
int askT;
vi rec; 

vi ask(int x) {
	rec.pb(x); 
	askT++; 
	v[x] = true; 
	vi ret; 
	printf("? %d\n", x); 
	fflush(stdout); 
	int k, c; 
	scanf( "%d", &k ); 
	assert(k > 0); 
	for (int i = 1; i <= k; ++i) {
		scanf( "%d", &c ); ret.pb( c ); 
	}
	return ret; 
	return E[x]; 
}

void answer(int x) {
	printf("! %d\n", x); 
	fflush(stdout); 
}

int main() {
	srand(time(0)); 
	int t; 
	scanf( "%d", &t ); 
	while (t--) {
		int h;
		scanf( "%d", &h ); 
		rec.clear(); 
		askT = 0; 
		for (int i = 1; i < (1<<h); ++i) { p[i] = i; E[i].clear(); }
		//for (int i = (1<<h)-1; i >= 1; --i) swap(p[i],p[rand()%i+1]); 
		for (int i = 2; i<(1<<h); ++i) {
			E[p[i]].pb(p[i/2]); 
			E[p[i/2]].pb(p[i]); 
			//cout<<p[i/2]<<' '<<p[i]<<endl; 
		}
		memset(v, false, sizeof(v)); 
		int x = rand()%((1<<h)-1)+1; 
		e[x] = ask(x);  
		a[1] = x; 
		tot = 1;
		while (e[x].size() == 3) {
			int x0 = x; 
			x = e[x0][rand()%3];
			while (v[x]) x = e[x0][rand()%3]; 
			e[x] = ask(x); 
			a[++tot] = x; 
		}
		if (e[x].size() == 2) {
			answer(x); 
			continue; 
		}
		for (int i = 1; i <= tot/2; ++i) swap(a[i],a[tot-i+1]); 
		x = a[tot]; 
		int fl = 0; 
		while (1) {
			bool flag = true; 
			//cout<<x<<endl; 
			for (auto i : e[x]) 
				if (!v[i]) flag = false; 
			if (flag) {
				tot--; 
				x = a[tot]; 
				continue; 
			}
			if (askT == 16 && tot == 6) {
				int s = 0; 
				for (auto i : e[x]) 
					if (!v[i]) s++; 
				if (s == 1) {
					for (auto i : e[x]) 
						if (!v[i]) {
							answer(i); 
							break; 
						}
					break; 
				}
			}
			int x0 = x; 
			x = e[x0][rand()%e[x0].size()];
			while (v[x]) x = e[x0][rand()%e[x0].size()]; 
			//cout<<x<<' '<<v[x]<<endl; 
			e[x] = ask(x); 
			a[++tot] = x; 
			if (e[x].size() == 2) {
				answer(x); 
				break; 
			}
			if (e[x].size() == 1) {
				tot = (tot+1) / 2; 
				x = a[tot]; 
				fl = tot; 
			}
			if (fl >= 4 && tot >= 7) {
				tot--; 
				x = a[tot]; 
			}
		}
		if (askT > 16) {
			printf( "Ask %d times.\n", askT ); 
			for (auto i : rec) cout<<i<<' '; 
			cout<<endl; 
		}
	}
}