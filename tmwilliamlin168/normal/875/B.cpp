#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    public:
        FenwickTree(int n) {
            _n=n;
            _ar=new int[n+1];
            for(int i=0; i<=n; ++i)
            	_ar[i]=0;
        };

        void add(int i, int x) {
            for(++i; i<=_n; i+=i&-i)
                _ar[i]+=x;
        }

        int prefSum(int n) {
            int sum=0;
            for(; n>0; n-=n&-n)
                sum+=_ar[n];
            return sum;
        }

        int sum(int si, int ei) {
            return prefSum(ei)-prefSum(si);
        }

        ~FenwickTree() {
            delete[] _ar;
        };
    private:
        int* _ar;
        int _n;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int *p = new int[n];
	for(int i=0; i<n; ++i) {
		cin >> p[i];
		p[i]=n-p[i];
	}
	FenwickTree tree(n);
	for(int i=0; i<=n; ++i) {
		int l=0, r=n, ans=l;
		while(l<=r) {
			int mid=(l+r)/2;
			if(tree.prefSum(mid)==mid) {
				ans=mid;
				l=mid+1;
			} else
				r=mid-1;
		}
		cout << i-ans+1 << " ";
		if(i<n)
			tree.add(p[i], 1);
	}
}