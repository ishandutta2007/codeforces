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

int n;
ll a[10010],b[10010];
int c[10010];
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	for(int i=0;i<n;i++){
		read(b[i]);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans+=b[i];
		for(int j=0;j<n;j++){
			if(a[i]&(((1ll<<62)-1)^a[j])){
				c[i]++;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<n;j++){
			if(c[j] == i-1){
				ans-=b[j];
				//cout<<j<<endl;
				for(int k=0;k<n;k++){
					if(a[k]&(((1ll<<62)-1)^a[j])) c[k]--;
				}
				c[j] = 0;
				goto nxt;
			}
		}
		if(i == 1)ans = 0;
		cout<<ans<<endl;
		return 0;
		nxt:;
	}
	cout<<0<<endl;
	return 0;
}