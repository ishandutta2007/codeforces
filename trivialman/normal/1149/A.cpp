#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 998244353;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,x,cnt;

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		cnt += (x==1);
	}
	if(cnt>=3){
		printf("1 1 1");
		rep(i,1,n-cnt) printf(" 2");
		rep(i,1,cnt-3) printf(" 1");
	}else if(cnt>=1){
		if(n-cnt>=1){
			printf("2 1");
			rep(i,1,n-cnt-1) printf(" 2");
			if(cnt==2) printf(" 1");
		}else{
			rep(i,1,n) printf("1 ");
		}
	}else{
		rep(i,1,n) printf("2 ");
	}
	return 0;
}