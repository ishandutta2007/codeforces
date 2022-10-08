#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const double eps=1e-6;
int n,l,r,ans; 
double ksm (double a,int t){
	double res = 1.0;
	while (t){
		if (t&1) res = res * a;
		a = a * a; t >>= 1;
	}
	return res;
}
int ksm (int a,int t){
	int res = 1;
	while (t){
		if (t&1) res = res * a;
		a = a * a; t >>= 1;
	}
	return res;
}
bool calc (int x,int t){
	int a=1;
	for (int i=1; i<=t; i++){
		a = a*x;
		if (a>r) return false;
	}
	return true;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	cin>>n>>l>>r;
	// d = x/y
	double lim = r*1.0/l;
	if (n==1) printf("%d\n", r-l+1);
	else if (n==2) printf("%I64d\n", (ll)(r-l+1)*(r-l));
	else {
		if (n>=25){puts("0");return 0;}
		for (int y=1; calc(y,n-1) ; y++){
			// x^n/y^n<=r/l
			for (int x=1; ksm(x*1.0/y,n-1)-eps <= lim && calc(x,n-1); x++){
				// l <= b <= r && l <= b*x^n/y^n <= r
				if (gcd(x,y)!=1 || x==y) continue;
				int d = ksm (y,n-1), g = ksm(x,n-1);
				// l / d <= k <= r/d
				int lpos = max((l+d-1)/d,(l+g-1)/g);
				lpos = max(lpos,1);
				int rpos = min(r/d,r/g);
				if (lpos<=rpos)
					ans += rpos - lpos +1;
			}
		}
		printf ("%d\n",ans);
	}
	return 0;
}