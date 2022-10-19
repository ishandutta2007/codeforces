#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int n, P[N * 2], id[N];
bool vis[N * 2];

vector <int> Ty, tmp;

vector <int> fuck(int a, int b, int c, int d) {
	vector <int> All;
	All.push_back(a); All.push_back(b); All.push_back(c); All.push_back(d);
	int A = P[a], B = P[b], C = P[c], D = P[d];
	vector <int> Ty;
	for(int i = 0; i < 4; ++ i) 
	if(A == All[i]) Ty.push_back(i);
	for(int i = 0; i < 4; ++ i) 
	if(B == All[i]) Ty.push_back(i);	
	for(int i = 0; i < 4; ++ i) 
	if(C == All[i]) Ty.push_back(i);
	for(int i = 0; i < 4; ++ i) 
	if(D == All[i]) Ty.push_back(i);
	if(Ty.size() < 4) exit(0 * puts("-1"));
	return Ty;
}


int kk(int x) {
	if(x % 2 == 0) return x - 1;
	else return x + 1;
}

map < vector <int>, int> Map;

int get(vector <int> who2) {
		int i0 = -1, i1 = -1;
		for(int i = 0; i < n * 2; ++ i) {
//			cerr << i <<' ' << (n * 2 + who2[(i + 2) % (n * 2)] - who2[i]) % (n * 2) << endl;
			if((n * 2 + who2[(i + 2) % (n * 2)] - who2[i]) % (n * 2) != 2) {
				return 1e9;
			}
			if(who2[i] == 0) i0 = i;
			if(who2[i] == 1) i1 = i;
		}
		int res = min(i0, n * 2 - i0);
		if((n * 2 - i1 + 1) % (n * 2) != i0) return 1e9; 
	return res;	
}

int main() {
	cin >> n;
	for(int i = 1; i <= n * 2; ++ i)
	scanf("%d", &P[i]);
	if(n % 2 == 0) {
		for(int i = 1; i <= n; i += 2) {
			vector <int> who  = fuck(i, i + 1, i + n + 1, i + n);
			if(!Ty.size()) {
				Ty = who;
			}
			else if(who != Ty) {
				puts("-1");
				return 0;
			}
		}
		int res = 0;
		Map[Ty] = 0;
		queue < vector <int> > q;q.push(Ty);
		while(!q.empty()) {
			vector <int> ind = q.front();
			q.pop();
			int it = Map[ind] + 1;
			swap(ind[0], ind[3]);
			swap(ind[1], ind[2]);
			if(!Map.count(ind)) {
				Map[ind] = it;
				q.push(ind);
			}
			swap(ind[0], ind[3]);
			swap(ind[1], ind[2]);
			swap(ind[0], ind[1]);
			swap(ind[2], ind[3]);
			if(!Map.count(ind)) {
				Map[ind] = it;
				q.push(ind);
			}
		}
		vector <int> tmp;
		tmp.push_back(0);
		tmp.push_back(1);
		tmp.push_back(2);
		tmp.push_back(3);
		if(!Map.count(tmp)) {
			res = -1;			
		} else res = Map[tmp];
		cout << res << endl;
		return 0;
	}
	
		
	vector <int> who;
	who.push_back(n);
	who.push_back(n + 1);
	vis[n] = vis[n + 1] = 1;
	while(who.size() < n * 2) {
		int now = who.back();
		vis[now] = 1;
		if(!vis[kk(now)]) {
			who.push_back(kk(now));
		} else {
			if(now > n) now -= n;
			else now += n;
			if(!vis[now]) who.push_back(now);
		}
	}
	vector <int> who2;
	for(int i = 1; i <= n * 2; ++ i) {
		for(int j = 0; j < (int) who.size(); ++ j) {
			if(P[who[i - 1]] == who[j]) who2.push_back(j);
		}
	}
	int res = -1;
	res = get(who2);
	if(res > 1e8) res = -1;
	cout << res << endl;
}