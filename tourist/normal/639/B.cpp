#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	int n, d, h;
	cin >> n >> d >> h;

	int bad = 0;
	if (d > h + h) bad = 1;

	if (d == 1 && n != 2) bad = 1;

	if (bad) {
		cout << "-1" << endl;
		return 0;
	}


	
	for (int i = 2; i <= h + 1; i++) cout << i << " " << i - 1<< endl;

	int last = h + 1;


	for (int i = 1; i <= d - h; i++) {
		if (i == 1) cout << 1; else cout << last + i - 1;
		cout << " " << last + i << endl;
	}

	int t = h + 1 + (d - h);
	
	int fi = 1;
	if (d == h) fi = 2;
	for (int i = t + 1; i <= n; i++) cout << i << " " << fi << endl;

	return 0;
}