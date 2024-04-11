#include <bits/stdc++.h>

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
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int n,q,x,y;
int cnt[100010][2];
int main() {
	read(n,q);
	int tt = 0;
	while(q--){
		read(x,y);
		x-=1;
		tt-=(cnt[y-1][x^1]+cnt[y][x^1]+cnt[y+1][x^1])*cnt[y][x];
		cnt[y][x]^=1;
		tt+=(cnt[y-1][x^1]+cnt[y][x^1]+cnt[y+1][x^1])*cnt[y][x];
		if(tt == 0)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}