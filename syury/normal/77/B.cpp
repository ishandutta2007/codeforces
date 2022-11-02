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

const ldb eps = 1e-9;

int a, b;
int t;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &t);
	F(i, 0, t){
		scanf("%d%d", &a, &b);
		if(a == 0 && b == 0){printf("1\n"); cont;}
		if(a == 0){printf("0.500000000\n"); cont;}
		if(b == 0){
			printf("1.0000000000\n"); cont;
		}
		ldb s = 2 * b * 1.0 * a, ps;
		ldb xi = a/4.0;
		if(xi < b - eps){
			ps = (b + (b - xi)) * a / 2.0;
		}
		else{
			ps = (4.0 * b * b)/2.0;
		}
		ps = s - ps;
		ps = ps/s;
		printf("%.12lf\n", (double)ps);
	}
	ret 0;
}