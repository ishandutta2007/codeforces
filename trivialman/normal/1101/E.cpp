#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e12;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,x,y,mx=0,my=0;
char ch;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d\n",&n);
	rep(i,1,n){
		scanf("%c %d %d\n",&ch,&x,&y);
		if(x<y) swap(x,y);
		if(ch=='+'){
			mx = max(mx, x);
			my = max(my, y);
		}else{
			printf( (mx<=x && my<=y) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}