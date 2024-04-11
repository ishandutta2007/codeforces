#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define tem template<class t,class...g>
#define D DD()
#define pri(k)tem auto p(t a,ll)->decltype(a.k,z()){D
#define DBP(...)void print(){D.x("{"#__VA_ARGS__,__VA_ARGS__);D,"}";}
#ifdef LOC
#define deb(...)((D,"<",__LINE__,"> ").x(#__VA_ARGS__,__VA_ARGS__),D,"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=long long;using Vi=vector<int>;
using Pii=pair<int,int>;struct DD{using z=void;z x(...){}tem z p(t a,...){cerr<<a;}
tem DD&operator,(t a){p(a,0);return*this;}pri(first),"(",a.first,", ",a.second,")";}
tem z x(const char*s,t a,g...k){while(*s&&*s!=',')D,*s++;D,": ",a,*s++;x(s,k...);}
pri(print());a.print();}pri(begin()),"[";each(k,a)D,k,", ";D,"]";}};

// ------------------------------------------------------------------------------------------ //

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k; cin >> n >> k;
	Vi perm(k);
	each(e, perm) cin >> e;

	vector<bool> seen(n+1);
	stack<int> que;
	que.push(n+1);

	int last = 0;
	seen[0] = true;

	each(e, perm) {
		seen[e] = true;
		while (que.top() < e) {
			if (que.top() != last+1) {
				cout << "-1\n";
				return 0;
			}
			last = que.top();
			que.pop();
		}
		que.push(e);
	}

	while (!que.empty()) {
		for (int i = que.top()-1; !seen[i]; i--) {
			perm.pb(i);
			seen[i] = true;
		}
		que.pop();
	}

	each(e, perm) cout << e << " ";
	cout << endl;
	return 0;
}