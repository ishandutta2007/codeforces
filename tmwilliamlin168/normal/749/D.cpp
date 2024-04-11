#include <bits/stdc++.h>
using namespace std;

vector<int> *bids;

struct cmp {
	bool operator()(const int &a, const int &b) {
		if(bids[a].empty())
			return true;
		if(bids[b].empty())
			return false;
		return bids[a].back()<bids[b].back();
	}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    bids = new vector<int>[n+1];
    int *p = new int[n+1];
    p[0]=0;
    bool *x = new bool[n+1]();
    for(int i=1; i<=n; ++i) {
    	int a, b;
    	cin >> a >> b;
    	bids[a].push_back(b);
    	p[i]=i;
	}
	stable_sort(p+1, p+n+1, cmp());
	int q;
	for(cin >> q; q>0; --q) {
		int k;
		cin >> k;
		int* l = new int[k];
		for(int i=0; i<k; ++i) {
			cin >> l[i];
			x[l[i]]=true;
		}
		int i1=-1, i2=-1;
		for(int i=n; i>=0; --i) {
			if(x[p[i]])
				continue;
			if(i1==-1)
				i1=p[i];
			else {
				i2=p[i];
				break;
			}
		}
		//cout << i1 << i2 << endl;
		if(i2==-1||bids[i1].empty())
			cout << "0 0\n";
		else
			cout << i1 << " " << bids[i1][upper_bound(bids[i1].begin(), bids[i1].end(), bids[i2].empty()?0:bids[i2].back())-bids[i1].begin()] << "\n";
		for(int i=0; i<k; ++i)
			x[l[i]]=false;
	}
}