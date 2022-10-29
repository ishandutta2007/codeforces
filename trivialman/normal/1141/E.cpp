#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

LL n, m, x, h, H, s[N];

int main() {
	#ifndef ONLINE_JUDGE 
	freopen("test.in","r",stdin);
	#endif
	scanf("%lld%lld",&H,&n);
	s[0] = m = h = 0;
	rep(i,1,n){
		scanf("%lld",&x);
		x = -x;
		s[i] = s[i-1]+x;
		h += x;
		m = max(m, s[i]);
	}
	if(h<=0 && m<H){
		cout<<-1<<endl;
		return 0;
	}
	LL round = (m>=H ? 0 : (H-m-1)/h+1);
	LL ans = round*n;
	rep(i,0,n) if(s[i]>=H-h*round){
		ans+=1ll*i;
		cout<<ans<<endl;
		break;
	}
}