#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int N = 1e5+5;
const double pi = acos(-1);
mt19937 rng(time(0));

int n;
LL a, r, m, h[N];

LL calc0(LL x){
	LL totl=0, totr=0, res;
	rep(i,1,n) if(h[i]<x) totl+=x-h[i]; else totr+=h[i]-x;
	res = totl * a + totr * r;
	return res;
}

LL calc(LL x){
	LL totl=0, totr=0, res;
	rep(i,1,n) if(h[i]<x) totl+=x-h[i]; else totr+=h[i]-x;
	if(totl>totr) res = totr * m + (totl-totr) * a;
	else res = totl * m + (totr-totl) * r;
	//cout<<x<<" "<<res<<endl;
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>n>>a>>r>>m;
	rep(i,1,n) scanf("%lld",h+i);
	sort(h+1, h+1+n);
	
	LL ans = 1ll<<62;
	if(m>=a+r){
		LL left = h[1], right = h[n];
		while(left<=right){
			LL diff = right - left, m1 = left + diff/3, m2 = left + diff*2/3;
			LL a1 = calc0(left), a2 = calc0(m1), a3 = calc0(m2), a4 = calc0(right);
			ans = min(ans, min(a1, min(a2, min(a3, a4))));
			if(a2<a3) right = m2-1;
			else left = m1+1;
		}
		return cout<<ans, 0;
	}
	
	LL left = h[1], right = h[n];
	while(left<=right){
		LL diff = right - left, m1 = left + diff/3, m2 = left + diff*2/3;
		LL a1 = calc(left), a2 = calc(m1), a3 = calc(m2), a4 = calc(right);
		ans = min(ans, min(a1, min(a2, min(a3, a4))));
		if(a2<a3) right = m2-1;
		else left = m1+1;
	}
	cout<<ans<<endl;
	
	return 0;
}