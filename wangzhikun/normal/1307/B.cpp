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

int T,n,x,cc;
int main() {
	read(T);
	while(T--){
		read(n);read(x);
		int ans = 1e9+10,cmx = -1;
		for(int i=1;i<=n;i++){
			read(cc);
			cmx = max(cmx,cc);
			if(cc == x){
				ans = 1;
			}
		}
		if((x+cmx-1)/cmx>2){
			ans = min(ans,(x+cmx-1)/cmx);
		}else{
			ans = min(ans,2);
		}
		cout<<ans<<endl;
	}
	return 0;
}