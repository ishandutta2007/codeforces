#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Point { int a,b; char c; };

int n,k;

const int MOD = 1000000007;

int p[200013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }
long long solve(vector<Point> X, int lim) {
	for (int i=0;i<2*lim;i++) p[i] = i;
	for (Point x: X) {
		int l = (abs(x.b-x.a+1-1)+1+1)/2;
		int r = (n-abs(x.b+x.a-1-n)+1)/2;
		int t = (x.c=='o');
		merge(l-1,r+lim*t);
		merge(l-1+lim,r+lim*(1-t));
	}
	for (int i=0;i<lim;i++) if (find(i)==find(i+lim)) return 0;
	long long ans = 1;
	int prev = 1;
	for (int i=0;i<2*lim;i++) if (find(i)==i && find(0)!=i && find(lim)!=i) {
		if (prev) ans = (ans*2)%MOD;
		prev^=1;
	}
	return ans;
}

int main() {
	scanf("%d%d",&n,&k);
	vector<Point> one,two;
	for (int i=0;i<k;i++) {
		Point pp;
		scanf("%d%d %c",&pp.a,&pp.b,&pp.c);
		if ((pp.a+pp.b)%2==0) one.push_back(pp);
		else two.push_back(pp);
	}
	printf("%lld\n",(solve(one,(n+1)/2+1)*solve(two,n/2+1))%MOD);

	return 0;
}