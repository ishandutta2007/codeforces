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

const int N = 200010;
int n,a[N],b[N],vis[N] = {0},req[N],ans = 0;
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		vis[a[i]] = 1;
	}
	int cp = 0;
	while(vis[cp+1]){
		cp+=1;
		req[cp] = 0;
		ans = max(ans,-cp+1);
	}
	for(int i=1;i<=n;i++){
		read(b[i]);
		vis[b[i]]+=1;
		while(vis[cp+1]){
			cp+=1;
			req[cp] = i;
			ans = max(ans,i-cp+1);
		}
	}
	int v2 = b[n],ok2 = 1;
	for(int i=n;i>=n-v2+1;i--){
		if(b[i]!=v2-(n-i))ok2 = 0;
	}
	if(ok2){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			vis[a[i]] = 1;
		}
		for(int i=v2+1;i<=n;i++){
			if(!vis[i])ok2 = 0;
			vis[b[i-v2]] = 1;
		}
		if(ok2){
			ans = n-v2-n;
		}
	}
	cout<<ans+n<<endl;
	
	return 0;
}