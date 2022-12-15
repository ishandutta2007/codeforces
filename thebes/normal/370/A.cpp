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
	int r1, c1, r2, c2; sc(r1, c1, r2, c2);
	if((r1 == r2) && (c1 == c2)) pr("0 0 0\n");
	else {
		//rook
		if((r1 == r2) || (c1 == c2)) pr(1, sp);
		else pr(2, sp);
		//bishop
		if(((r1 + c1) & 1) != ((r2 + c2) & 1)) pr(0, sp);
		else {
			bool flag = false;
			for(int i = 0; i < 8; i++) {
				if(r1 + i == r2 && c1 + i == c2) flag = true;
				if(r1 - i == r2 && c1 - i == c2) flag = true;
				if(r1 + i == r2 && c1 - i == c2) flag = true;
				if(r1 - i == r2 && c1 + i == c2) flag = true;
			}
			if(flag) pr(1, sp);
			else pr(2, sp);
		}
		//king
		pr(max(abs(r1 - r2), abs(c1 - c2)), nl);
	}
}