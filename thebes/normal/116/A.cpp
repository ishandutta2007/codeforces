#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define pu push
#define pb push_back
#define em emplace
#define eb emplace_back
#define sp ' '
#define nl '\n'
#define f first
#define s second
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
	int cur = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		int out, in; sc(out, in);
		cur -= out; cur += in;
		ans = max(ans, cur);
	}
	pr(ans, nl);
}