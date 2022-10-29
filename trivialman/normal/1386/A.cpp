#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 1e5+5;
mt19937 rng(time(0));
 
int T;
LL n, realc, lastx;
bool isauto = false;

bool ask(LL x){
	bool leq;
	cout<<"? "<<x<<endl;
	if (isauto)
		leq = abs(lastx - x) >= realc;
	else
		cin>>leq;
	lastx = x;
	return leq;
}
// jump from right to left initially
LL calcinit(LL n){
	if (n==1) return 1;
	if (n%2==0) return n + 1 - calcinit(n/2);
	else return n + 1 - calcinit((n+1)/2);
}

LL guess(LL x, LL l, LL r, LL op){
	if (l==r) return l;
	LL bar = l + r - 1 >> 1;
	x += op * bar;
	
	bool leq = ask(x);
	if (leq) r = bar;
	else l = bar + 1;
	return guess(x, l, r, -op);
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	
	if (isauto) T = 1;
	else cin>>T;
	while(T--){
		if (isauto) n = 7, realc = 4;
		else cin>>n;
		
		LL x = calcinit(n);
		
		ask(x);
		cout<<"= "<<guess(x, 1, n, -1)<<endl;
		if(isauto) cout<<realc<<endl;
	}
	
	return 0;
}