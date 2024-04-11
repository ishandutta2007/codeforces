#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,a[1000010],ra[1000010],b[1000010];
ll rans = 1e18;
void solve(ll val){
	//cout<<val<<endl;
	ll cs = 0;
	for(int i=0;i<n;i++){
		a[i]=ra[i]%val;
		cs+=a[i];
	}
	ll l = 0,r = -1,ans = 0;
	while(l!=n && cs!=0){
		cs-=val;
		r = l-1;
		ll csu = 0,mdit = 0;
		while(csu<val){
			r++;
			b[r] = min(val-csu,a[r]);
			csu+=a[r];
		}
		for(ll i=l;i<=r;i++){
			mdit+=(i-l)*b[i];
		}
		ll cans = 1e18;
		ll csum = 0;
		//cout<<l<<' '<<r<<endl;
		for(ll i=l;i<=r;i++){
			cans = min(cans,mdit);
			csum+=b[i];
			mdit+=csum;
			mdit-=val-csum;
		}
		//cout<<cans<<endl;
		ans+=cans;
		for(ll i=l;i<=r;i++)a[i]-=b[i];
		while(a[l] == 0 && l<n)l++;
	}
	rans = min(rans,ans);
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	ll su = 0;
	for(int i=0;i<n;i++){
		cin>>ra[i];
		su+=ra[i];
	}
	if(su == 1){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> S;
	for(ll j=2;j*j<=su;j++){
		if(su%j == 0){
			int ok1 = 1,ok2 = 1;
			for(auto ct:S)if(j%ct == 0)ok1 = 0;
			if(ok1){
				solve(j);
				S.push_back(j);
			}
		}
	}
	for(ll j=2;j*j<=su;j++){
		if(su%j == 0){
			int ok1 = 1,ok2 = 1;
			for(auto ct:S)if((su/j)%ct == 0)ok2 = 0;
			if(ok2){
				solve(su/j);
				S.push_back(su/j);
			}
		}
	}
	
	
	//cout<<"233"<<endl;
	solve(su);
	cout<<rans<<endl;
	return 0;
}