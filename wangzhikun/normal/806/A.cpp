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

ll t;
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int main() {
	read(t);
	while(t--){
		ll x,y,p,q;
		read(x);read(y);read(p);read(q);
		
		y-=x;
		ll d = gcd(p,q);
		q-=p;
		if(p == 0 && x!=0){
			cout<<-1<<endl;
			continue;
		}
		if(q == 0 && y!=0){
			cout<<-1<<endl;
			continue;
		}
		if(p == 0 && x==0){
			cout<<0<<endl;
			continue;
		}
		if(q == 0 && y==0){
			cout<<0<<endl;
			continue;
		}
		p/=d;
		q/=d;

		ll cm = max((x+p-1)/p,(y+q-1)/q);
		cout<<cm*(p+q)-x-y<<endl;
	}
	return 0;
}