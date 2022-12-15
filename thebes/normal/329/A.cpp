#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define al(x) (x).begin(), (x).end()
#define ms(a, b) memset(a,b,sizeof(a))
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t, A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; sc(n);
	char a[n + 1][n + 1];
	bool r[n + 1], c[n + 1];
	ms(r, false); ms(c, false);
	for(int i = 1; i <= n; i++) {
		gc();
		for(int j = 1; j <= n; j++) {
			gc(a[i][j]);
			if(a[i][j] == '.') {
				r[i] = true;
				c[j] = true;
			}
		}
	}
	//one in every row, one in every col?
	bool okr = true, okc = true;
	for(int i = 1; i <= n; i++) if(!r[i]) okr = false;
	for(int i = 1; i <= n; i++) if(!c[i]) okc = false;
	if(!okr && !okc) {
		pr(-1, nl);
		return 0;
	}
	if(okr) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(a[i][j] == '.') {
					pr(i, sp, j, nl);
					break;
				}
			}
		}
	} else {
		for(int j = 1; j <= n; j++) {
			for(int i = 1; i <= n; i++) {
				if(a[i][j] == '.') {
					pr(i, sp, j, nl);
					break;
				}
			}
		}
	}
}