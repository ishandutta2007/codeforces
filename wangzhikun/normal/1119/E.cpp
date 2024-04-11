#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll ans = 0;
ll n,a[300030];
int main() {
	read(n);
	ll ans = 0,rem = 0;
	for(int i=0;i<n;i++){
		read(a[i]);
		ll cu1 = min(rem,a[i]/2);
		a[i]-=cu1*2;
		rem-=cu1;
		ans+=cu1;
		ans+=a[i]/3;
		rem+=a[i]%3;
	}
	cout<<ans<<endl;
	return 0;
}