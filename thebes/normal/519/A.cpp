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
	int white = 0, black = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			char c; gc(c);
			if(c == 'Q') white += 9;
			else if(c == 'q') black += 9;
			else if(c == 'R') white += 5;
			else if(c == 'r') black += 5;
			else if(c == 'B') white += 3;
			else if(c == 'b') black += 3;
			else if(c == 'N') white += 3;
			else if(c == 'n') black += 3;
			else if(c == 'P') white += 1;
			else if(c == 'p') black += 1;
		}
		gc();
	}
	if(white > black) pr("White", nl);
	else if(black > white) pr("Black", nl);
	else pr("Draw", nl);
}