#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5;

ll cnt=0;
int n, m, t, d;
struct anime {
	int a, c;
} b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
    	cin >> b[i].a;
    	cnt += b[i].a;
    }
    for(int i = 0; i < n; ++i) cin >> b[i].c;

    vector<int> p(n);
    for(int i = 0; i < n; ++i) p[i] = i;
    //make_heap(p.begin(), p.end());
	sort(p.begin(), p.end(), [&](int i, int j) {
		return b[i].c < b[j].c;
	});
	int pfirst = 0;

	while(m--) {
		ll res = 0;
		cin >> t >> d; --t;

		if(cnt != 0) {
			if(b[t].a < d) {
				res = (ll)b[t].c * b[t].a;
				d -= b[t].a;
				cnt -= b[t].a;
				//cout << "not enough d = " << d << ", res = " << res << endl;
				b[t].a = 0;

				while(cnt != 0 && d != 0 && pfirst < p.size()) {
					int t = p[pfirst];
					if(b[t].a < d) {
						res += (ll)b[t].a * b[t].c;
						d -= b[t].a;
						cnt -= b[t].a;
						b[t].a = 0;

						//cout << "pfirst = " << pfirst << endl;
						++pfirst;
					}
					else {
						res += (ll)b[t].c * d;
						b[t].a -= d;
						cnt -= d;
						d = 0;
					}
				}

				if(d != 0) res = 0;
			}
			else {
				res = (ll)b[t].c*d;
				b[t].a -= d;
				cnt -= d;
				d = 0;
			}
		}

		cout << res << endl;
	}
}