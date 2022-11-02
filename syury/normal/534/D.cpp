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

int n;
set<pair<int, int> >a[3];
int cnt = 0;
queue<int> ans;

int main(){
	scanf("%d", &n);
	F(i, 0, n){
		int x;
		scanf("%d", &x);
		a[x%3].ins(mk(x, i + 1));
	}
	while(true){
		if(a[0].empty() && a[1].empty() && a[2].empty())brk;
		auto it = a[cnt%3].upper_bound(mk(cnt, n + 10));
		if(it == a[cnt%3].begin()){printf("Impossible"); ret 0;}
		it--;
		//printf("Pair (%d, %d)\n", it->X, it->Y);
		ans.push(it->Y);
		int x = it->X;
		a[cnt%3].era(it);
		cnt = x + 1;
	}
	printf("Possible\n");
	while(!ans.empty()){
		printf("%d ", ans.front());
		ans.pop();
	}
	ret 0;
}