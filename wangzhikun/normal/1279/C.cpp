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

ll t,m,n,po[100010];

int main() {
	read(t);
	while(t--){
		read(n);read(m);
		for(int i=1;i<=n;i++){
			int cc;
			read(cc);
			po[cc] = i;
		}
		int cmx = 0;
		ll ans = 0;
		for(int i=1;i<=m;i++){
			int cc;
			read(cc);
			int cp = po[cc];
			//cout<<cp<<' '<<ans<<endl;
			if(cp<cmx){
				ans+=1;
			}else{
				cmx = cp;
				ans+=(cp-(i-1)-1)*2+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}