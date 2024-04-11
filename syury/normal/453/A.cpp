#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
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
#define y1 adjf
#define tm afhdhn

int m, n;
ldb ans = 0.0;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d%d", &m, &n);
	F(i, 1, m + 1){
		ans += i * (pow(i * 1.0/m, n) - pow((i - 1) * 1.0/m, n));
	}
	printf("%.15lf", (double)ans);
	ret 0;
}