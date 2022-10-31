#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int lsb(int x) { return x&-x; }

int n;
vector<int> x, y;
vector<int> basisX, basisY;

bool comp(int a, int b) { return lsb(x[a])<lsb(x[b]); }
vector<pair<int,int> > gauss() {
	vector<pair<int,int> > res;
	for (int i=0;i<n;i++) {
		for (int j: basisX) {
			if (x[i]&lsb(x[j])) {
				x[i]^=x[j], res.push_back(MP(i,j));
			}
		}
		if (!x[i]) continue;
		for (int j: basisX) {
			if (x[j]&lsb(x[i])) {
				x[j]^=x[i], res.push_back(MP(j,i));
			}
		}
		basisX.push_back(i);
	}
	sort(basisX.begin(),basisX.end(),comp);
	return res;
}

vector<pair<int,int> > conv() {
	vector<pair<int,int> > res;
	while (basisY.size()) {
		while (basisX.size() && lsb(x[basisX[0]])!=lsb(y[basisY[0]])) {
			res.push_back(MP(basisX[0],basisX[0]));
			basisX.erase(basisX.begin());
		}
		if (!basisX.size()) printf("-1\n"), exit(0);
		for (int i: basisX) {
			if (i!=basisX[0] && ((x[basisX[0]]^y[basisY[0]])&lsb(x[i]))) {
				x[basisX[0]]^=x[i];
				res.push_back(MP(basisX[0],i));
			}
		}
		if (x[basisX[0]]!=y[basisY[0]]) printf("-1\n"), exit(0);
		if (basisX[0]!=basisY[0]) {
			swap(x[basisX[0]],x[basisY[0]]);
			for (int& i: basisX) if (i==basisY[0]) i = basisX[0];
			res.push_back(MP(basisX[0],basisY[0]));
			res.push_back(MP(basisY[0],basisX[0]));
			res.push_back(MP(basisX[0],basisY[0]));
		}
		basisX.erase(basisX.begin());
		basisY.erase(basisY.begin());
	}
	for (int i: basisX) res.push_back(MP(i,i));
	return res;
}

int main() {
	scanf("%d",&n);
	x.resize(n);
	y.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&x[i]);
	for (int i=0;i<n;i++) scanf("%d",&y[i]);
	vector<pair<int,int> > resX, resY, resC;
	for (int d=0;d<2;d++) {
		resX = gauss();
		swap(resX,resY); swap(x,y); swap(basisX,basisY);
	}
	resC = conv();
	printf("%d\n",resX.size()+resC.size()+resY.size());
	reverse(resY.begin(),resY.end());
	for (auto p: resX) printf("%d %d\n",p.A+1,p.B+1);
	for (auto p: resC) printf("%d %d\n",p.A+1,p.B+1);
	for (auto p: resY) printf("%d %d\n",p.A+1,p.B+1);

	return 0;
}