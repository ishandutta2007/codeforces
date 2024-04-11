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

const ldb eps = 1e-7;

int a, b, m, vx, vy, vz;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d%d%d%d", &a, &b, &m, &vx, &vy, &vz);
	ldb t = - (m * 1.0 / vy);
	ldb x = a/2.0 + t * vx;
	ldb z = t * vz;
	int r = int(z/b + eps);
	int c = int(x/a + eps);
	if(x > -eps)c++;
	int wh = 0;
	if(c > 0)wh = (c + 1)%2;
	else wh = 1 - abs(c)%2;
	int cnt = r%2;
	if(cnt == 1)wh = 3 - wh;
	x -= (c - 1) * a;
	z -= r * b;
	if(wh == 1){
		x = a - x;
	}
	if(wh == 2){
		x = a - x;
		z = b - z;
	}
	if(wh == 3)z = b - z;
	printf("%.12lf %.12lf", (double)x, (double)z);
	ret 0;
}