#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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
#define tm dhgdg

const ldb PI = acos(-1.0);
const int MAXN = 20;
const ldb eps = 1e-9;

int n, l, r;
ldb dp[1<<MAXN];
int x[MAXN], y[MAXN];
int a[MAXN];
ldb sa[MAXN];
ldb ca[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &l, &r);
	F(i, 0, n){
		scanf("%d%d%d", &x[i], &y[i], &a[i]);
		sa[i] = sin(a[i] * PI / 180.0);
		ca[i] = cos(a[i]*PI/180.0);
	}
	dp[0] = 0;
	ldb kek = 0;
	F(mask, 1, 1<<n){
		dp[mask] = 0;
		F(i, 0, n){
			if(!(mask&(1<<i)))cont;
			int prv = mask^(1<<i);
			ldb px = l + dp[prv];
			/*ldb d = sqrt((x[i] - px) * (x[i] - px) + y[i] * y[i]);
			ldb vc = fabs(y[i])/d;
			//vc /= d * d1;
			ldb cs = fabs((x[i]-px))/d;
			//cs /= d * d1;
			vc = sa[i] * cs + vc * ca[i];
			//vc /= d * d1;
			if(fabs(vc - 0) < eps){printf("%d", r - l); ret 0;}*/
			ldb dx = px - x[i], dy = -y[i];
			ldb old_dx = dx;
			dx = dx * ca[i] - dy * sa[i];
			dy = old_dx * sa[i] + dy * ca[i];
//			printf("mask = %d i = %d dx = %.15lf dy = %.15lf\n", mask, i, (double)dx, (double)dy);
			if(fabs(dy - 0) < 1e-6){printf("%d", r - l); ret 0;}
			dx /= dy; dy /= dy;
//			printf("dx = %.15lf\n", (double)dx);
			ldb len = x[i] - y[i] * dx - l;
			if(len - dp[prv] < -eps){printf("%d", r - l); ret 0;}
			if(len - dp[mask] > eps)dp[mask] = len;
		}
		if(dp[mask] - (r - l) > -eps){printf("%d", r - l); ret 0;}
		if(dp[mask] - kek > eps)kek = dp[mask];
	}
	printf("%.15lf", (double)kek);
	ret 0;
}