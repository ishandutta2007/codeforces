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
#define tm afhdhn

const int MAXN = 1e5 + 5;
int cnt[MAXN];

vector<int> a;
int n;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n); fi0(cnt);
	F(i, 0, n)scanf("%d", &a[i]);
	sort(all(a)); cnt[0] = 1;
	F(i, 1, n){
		if(a[i] - a[i - 1] > 1){printf("NO"); ret 0;}
		cnt[a[i] - a[0]]++;	
	}
	int ptr = 0;
	while(true){
		if(cnt[ptr] == 0)brk;
		if(cnt[ptr] == 1 && cnt[ptr + 1] == 0)brk;
		if(cnt[ptr] > 1 && cnt[ptr + 1] == 0){printf("NO"); ret 0;}
		if(cnt[ptr + 2] == 0){
			if(cnt[ptr] == cnt[ptr + 1])brk;
			printf("NO"); ret 0;
		}
		if(cnt[ptr + 1] >= cnt[ptr] + 1)cnt[ptr + 1] -= cnt[ptr];
		else {printf("NO"); ret 0;}
		ptr++;
	}
	printf("YES");
	ret 0;
}