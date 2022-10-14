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

int n,q,a[200010],cnt[200020],color[200020],l[200010],r[200010];
int main() {
	read(n);read(q);
	for(int i=1;i<=n;i++){
		read(a[i]);
		cnt[a[i]]+=1;
		color[a[i]] = a[i];
		if(l[a[i]] == 0){
			l[a[i]] = r[a[i]] = i;
		}
		r[a[i]] = i;
	}
	int p = 1,ans = 0;
	while(p!=n+1){
		int cr = r[a[p]];
		int mx = cnt[a[p]];
		for(int i=p;i<=cr;i++){
			if(color[a[i]]!=a[p]){
				mx = max(mx,cnt[a[i]]);
				color[a[i]] = a[p];
				cr = max(cr,r[a[i]]);
			}
		}
		ans+=cr-p+1-mx;
		p = cr+1;
	}
	cout<<ans<<endl;
	return 0;
}