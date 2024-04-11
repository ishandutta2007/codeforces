#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=200005;
int n;
LL a[N];
map<LL,LL>f;
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	f[a[1]-1]=0;
	rep(i,2,n){
		while(SZ(f)){
			auto t=*--f.end();
			if(t.X<a[i])break;
			f.erase(--f.end());
			umax(f[t.X%a[i]],t.Y+1LL*(i-1)*(t.X-t.X%a[i]));
			umax(f[a[i]-1],t.Y+1LL*(i-1)*((t.X+1)/a[i]*a[i]-a[i]));
		}
	}
	LL ans=0;
	for(auto x:f)umax(ans,1LL*x.X*n+x.Y);
	printf("%lld\n",ans);
	return 0;
}