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

ll ans  = 0;
int n,a[300030],su[2][1100010];
int main() {
	read(n);
	int cc = 0;
	for(int i=0;i<=n;i++){
		ans+=su[i&1][cc];
		su[i&1][cc]+=1;
		if(i == n)break;
		read(a[i]);
		cc^=a[i];
	}
	cout<<ans<<endl;
	return 0;
}