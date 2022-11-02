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

const int S = 1000000;

int n;
bool used[S + 2];
int out[S + 2];
int sz = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(used);
	scanf("%d", &n);
	F(i, 0, n){
		int x;
		scanf("%d", &x);
		used[x] = true;
	}
	int i = 1;
	int pn = 0;
	while(i < S + 1 - i){
		if(used[i] && !used[S + 1 - i]){
			used[S + 1 - i] = true; out[sz++] = S + 1 - i; i++; cont;
		}
		if(!used[i] && used[S + 1 - i]){
			used[i] = true; out[sz++] = i; i++; cont;
		}
		if(used[i] && used[S + 1 - i])pn++;
		i++;
	}
	i = 1;
	while(i < S + 1 - i){
		if(!used[i] && !used[S + 1 - i] && pn > 0){
			out[sz++] = i; out[sz++] = S + 1 - i; pn--;
		}
		i++;
	}
	printf("%d\n", sz);
	F(i, 0, sz)printf("%d ", out[i]);
	ret 0;
}