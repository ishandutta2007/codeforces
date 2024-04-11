#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 3e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int n, m, a[N][8], num1[N], num2[N];
int ans = -1, ansi, ansj;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,0,m-1) scanf("%d",&a[i][j]);
	rep(i,1,n)rep(j,m,7) a[i][j] = 1e9;
	
	rep(k,0,127){
		rep(i,1,n){
			num1[i] = num2[i] = 1e9;
			rep(j,0,7){
				if(k >> j & 1){
					num1[i] = min(num1[i], a[i][j]);
				}else{
					num2[i] = min(num2[i], a[i][j]);
				}
			}
		}
		int x = max_element(num1+1, num1+n+1) - num1;
		int y = max_element(num2+1, num2+n+1) - num2;
		int num = min(num1[x], num2[y]);
		if(num > ans){
			ans = num, ansi = x, ansj = y;
		}
	}
	cout<<ansi<<" "<<ansj<<endl;
	return 0;
}