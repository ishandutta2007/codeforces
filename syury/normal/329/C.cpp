#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf

int n, m;
set<pair<int, int> > kek;
int lol[111111];

void shuffle(){
	F(i, 0, n){
		int j = rand()%(i+1);
		swap(lol[i], lol[j]);
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		if(v > u)swap(v, u);
		kek.ins(mk(v, u));
	}
	F(i, 0, n)lol[i] = i;
	clock_t bg = clock();
	srand(time(NULL));
	while((clock()-bg)/double(CLOCKS_PER_SEC) <= 1.4){
		shuffle();
		if(m == n){
			bool good = true;
			F(i, 0, n){
				int nxt = i + 1; if(nxt == n)nxt = 0;
				int v = lol[i], u = lol[nxt];
				if(v > u)swap(v, u);
				if(kek.count(mk(v, u))){good = false; brk;}
			}
			if(!good)cont;
			F(i, 0, n){
				int v = lol[i], u = (i == n - 1) ? lol[0] : lol[i + 1];
				printf("%d %d\n", v + 1, u + 1);
			}
			ret 0;
		}
		bool good = true;
		F(i, 0, m){
			int v = lol[i], u = lol[i + 1];
			if(v > u)swap(v, u);
			if(kek.count(mk(v, u))){good = false; brk;}
		}
		if(!good)cont;
		F(i, 0, m){
			printf("%d %d\n", lol[i] + 1, lol[i + 1] + 1);
		}
		ret 0;
	}
	printf("-1");
	ret 0;
}