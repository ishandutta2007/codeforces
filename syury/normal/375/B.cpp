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

const int MAXN = 5005;

int n, m;
int a[MAXN][MAXN];
int ri[MAXN][MAXN];
int so[MAXN][MAXN];

char myget(){
	char c = getc(stdin);
	while(!isdigit(c))c = getc(stdin);
	ret c;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, n){
		F(j, 0, m)a[i][j] = myget() - '0';
	}
	Df(j, m - 1, -1){
		if(j == m - 1){
			int ptr = 0;
			F(i, 0, n)if(a[i][j] == 0){ri[i][j] = 0; so[j][ptr++] = i;}
			F(i, 0, n)if(a[i][j] == 1){ri[i][j] = 1; so[j][ptr++] = i;}
			cont;
		}
		int ptr = 0;
		F(i, 0, n)if(a[i][j] == 0){ri[i][j] = 0; so[j][ptr++] = i;}else{ri[i][j] = 1 + ri[i][j + 1];}
		F(i, 0, n)if(a[i][j] == 1 && a[i][j + 1] == 0){so[j][ptr++] = i;}
		F(i, 0, n){
			int _i = so[j + 1][i];
			if((a[_i][j] & a[_i][j + 1]) != 1)cont;
			so[j][ptr++] = _i;
		}
	}
	int ans = 0;
	F(j, 0, m){
		int ptr = 0;
		F(len, 1, m - j + 1){
			while(ptr < n && ri[so[j][ptr]][j] < len)ptr++;
			ans = max(ans, len * (n - ptr));
		}
	}
	printf("%d", ans);
	ret 0;
}