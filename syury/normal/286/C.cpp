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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e6 + 6;

int n, m;
int q[MAXN];
int p[MAXN];
int stk[MAXN];
int ptr = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &p[i]);
	scanf("%d", &m);
	F(i, 0, m)scanf("%d", &q[i]), q[i] = n - q[i];
	reverse(p, p + n); sort(q, q + m);
	int qp = 0;
	F(i, 0, n){
		if(qp < m && q[qp] == i){
			qp++;
			stk[ptr++] = p[i]; cont;
		}
		if(ptr == 0){stk[ptr++] = p[i]; cont;}
		int tp = stk[ptr - 1];
		if(tp == p[i]){ptr--; p[i] = -p[i];}
		else {stk[ptr++] = p[i];}
	}
	if(ptr != 0){printf("NO"); ret 0;}
	F(i, 0, n)p[i] = -p[i];
	reverse(p, p + n);
	printf("YES\n");
	F(i, 0, n)printf("%d ", p[i]);
	ret 0;
}