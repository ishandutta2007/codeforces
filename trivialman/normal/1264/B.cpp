#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a,b,c,d;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>a>>b>>c>>d;
	if(abs(a+c-(b+d))>1){
		cout<<"NO\n";
		return 0;
	}
	
	if(a==0 && b==0 && abs(c-d)<=1){
		printf("YES\n");
		if(c>=d){
			rep(i,1,d) printf("2 3 ");
			if(c>d) printf("2 ");
		}else{
			rep(i,1,c) printf("3 2 ");
			printf("3 ");
		}
		return 0;
	}
	if(c==0 && d==0 && abs(a-b)<=1){
		printf("YES\n");
		if(a>=b){
			rep(i,1,b) printf("0 1 ");
			if(a>b) printf("0 ");
		}else{
			rep(i,1,a) printf("1 0 ");
			printf("1 ");
		}
		return 0;
	}
	
	if(a>b || d>c){
		cout<<"NO\n";
		return 0;
	} 
	printf("YES\n");
	if(a+c>=b+d){
		rep(i,1,a) printf("0 1 ");
		b -= a;
		rep(i,1,b) printf("2 1 ");
		c -= b;
		rep(i,1,d) printf("2 3 ");
		if(c>d) printf("2 ");
	}else{
		rep(i,1,d) printf("3 2 ");
		c -= d;
		rep(i,1,c) printf("1 2 ");
		b -= c;
		rep(i,1,a) printf("1 0 ");
		if(b>a) printf("1 ");
	}
	return 0;
}