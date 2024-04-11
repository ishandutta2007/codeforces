// hate it
// 1<<63 - BAD (except on TC apparently works?!)
// 1LL<<63 - GOOD
// lost too much time over this -> STOP doing it

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MP make_pair
#define A first
#define B second

#define ull unsigned long long

struct Flight {
	int a,b,d;
	bool operator<(Flight o) const { return d<o.d; }
};

vector<vector<ull> > conv1(vector<vector<bool> > a) {
	vector<vector<ull> > res = vector<vector<ull> >(a.size(),vector<ull>((a[0].size()+63)/64));
	for (int i=0;i<a.size();i++) for (int j=0;j<a[0].size();j++) if (a[i][j]) res[i][j/64]|=(1LL<<(j%64));
	return res;
}
vector<vector<ull> > conv2(vector<vector<bool> > a) {
	vector<vector<ull> > res = vector<vector<ull> >((a.size()+63)/64,vector<ull>(a[0].size()));
	for (int i=0;i<a.size();i++) for (int j=0;j<a[0].size();j++) if (a[i][j]) res[i/64][j]|=(1LL<<(i%64));
	return res;
}

vector<vector<bool> > mult2(vector<vector<ull> > a, vector<vector<ull> > b) {
	vector<vector<ull> > tmp = vector<vector<ull> >(a.size(),vector<ull>(b[0].size()));
	vector<vector<bool> > res = vector<vector<bool> >(a.size(),vector<bool>(b[0].size()));
	for (int i=0;i<a.size();i++) for (int j=0;j<b[0].size();j++) {
		for (int k=0;k<a[0].size();k++) tmp[i][j]=tmp[i][j]|(a[i][k]&b[k][j]);
		res[i][j] = (tmp[i][j]>0);
	}
	return res;
}

vector<vector<bool> > mult(vector<vector<bool> > a, vector<vector<bool> > b) {
	vector<vector<ull> > aa = conv1(a), bb = conv2(b);
	return mult2(aa,bb);
}

int n,m;
vector<vector<bool> > adj;
vector<Flight> flights;
vector<vector<bool> > can;
vector<vector<bool> > trans;
vector<vector<bool> > adjC;

int best[250];
queue<int> frontier;
int check() {
	for (int i=0;i<n;i++) best[i] = 1.05e9;
	for (int i=0;i<n;i++) if (can[0][i]) {
		best[i] = 0;
		frontier.push(i);
	}
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		for (int i=0;i<n;i++) if (adj[x][i] && best[i]==(int) 1.05e9) {
			best[i] = best[x]+1;
			frontier.push(i);
		}
	}
	return best[n-1];
}

void make(int diff) {
	trans = vector<vector<bool> >(n,vector<bool>(n));
	for (int i=0;i<n;i++) trans[i][i] = 1;
	adjC = adj;
	while (diff) {
		if (diff%2) trans = mult(trans,adjC);
		adjC = mult(adjC,adjC);
		diff/=2;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		flights.push_back({a-1,b-1,d});
	}
	adj = vector<vector<bool> >(n,vector<bool>(n));
	sort(flights.begin(),flights.end());
	int ans = 1.05e9;
	can = vector<vector<bool> >(1,vector<bool>(n));
	can[0][0] = 1;
	int prev = 0;
	for (Flight f: flights) {
		make(f.d-prev);
		can = mult(can,trans);
		adj[f.a][f.b] = 1;
		ans = min(ans,f.d+check());
		prev = f.d;
	}
	if (ans==(int) 1.05e9) printf("Impossible\n");
	else printf("%d\n",ans);

	return 0;
}