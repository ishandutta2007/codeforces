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

ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}

ll x[120],y[120],ax,ay,bx,by,xs,ys,t;

int main() {
	read(x[0],y[0],ax,ay,bx,by);
	read(xs,ys,t);
	int n = 0;
	for(int j=1;;j++){
		x[j] = x[j-1]*ax+bx;
		y[j] = y[j-1]*ay+by;
		if(x[j]+y[j]>1e16*4){
			n = j;
			break;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(min(dist(xs,ys,x[i],y[i]),dist(xs,ys,x[j],y[j]))+dist(x[i],y[i],x[j],y[j])<=t){
				ans = max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}