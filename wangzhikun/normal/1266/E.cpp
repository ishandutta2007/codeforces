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

int n,q,a[200010],s,t,u;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
__gnu_pbds::gp_hash_table<int,int> L[200010];

ll ans = 0;
int main() {
	read(n);
	ll ans = 0;
	a[0] = -1e9;
	for(int i=1;i<=n;i++){
		read(a[i]);
		ans+=a[i];
	}
	read(q);
	for(int i=0;i<q;i++){
		read(s);read(t);read(u);
		a[L[s][t]]+=1;
		if(a[L[s][t]]>0)ans+=1;
		L[s][t] = u;
		a[L[s][t]]-=1;
		if(a[L[s][t]]>=0)ans-=1;
		cout<<ans<<endl;
	}
	return 0;
}