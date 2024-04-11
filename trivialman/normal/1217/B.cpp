#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 105;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T,n,x,d[N],h[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		rep(i,1,n)scanf("%d%d",d+i,h+i);
		int ma1 = 0, ma2 = 0;
		rep(i,1,n){
			ma1 = max(ma1, d[i]-h[i]);
			ma2 = max(ma2, d[i]);
		}
		//cout<<ma1<<" "<<ma2<<endl;
		int ans = 0;
		x -= ma2;
		if(x>0 && ma1==0) ans = -1;
		else if(x<=0) ans = 1;
		else ans = (x+ma1-1) / ma1 + 1;
		printf("%d\n",ans);
	}
	return 0;
}