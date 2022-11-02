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

int n;
ldb a[101];
ldb cr = 0.0, ap = 1.0;
ldb mx = 0.0;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n){
		double tmp;
		scanf("%lf", &tmp);
		ldb p = tmp;
		a[i] = p;
		//if(p - mx > eps)mx = p;
		//cr = cr * (1 - p) + ap * p;
		//ap = ap * (1 - p);
	}
	sort(a, a + n);
	F(i, 0, n){
		cr = 0.0, ap = 1.0;
		F(j, i, n){
			cr = cr * (1 - a[j]) + ap * a[j];
			ap = ap * (1 - a[j]);
			if(cr - mx > eps)mx = cr;
		}
	}
	//if(mx - 0.5 > -eps){printf("%.12lf", (double)mx);}
	//else printf("%.12lf", (double)cr);
	printf("%.12lf", (double)mx);
	ret 0;
}