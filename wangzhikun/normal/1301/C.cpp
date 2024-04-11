#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

ll T,n,m;
ll C(ll x){return x*(x+1)/2;}
int main() {
	read(T);
	while(T--){
		read(n);read(m);
		ll mi = (n-m)/(m+1);
		ll typ2 = (n-m)-mi*(m+1);
		cout<<C(n)-typ2*C(mi+1)-(m+1-typ2)*C(mi)<<endl;
	}
	return 0;
}