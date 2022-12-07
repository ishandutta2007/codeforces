#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100006;
int n,x[N],y[N];
int cnt[2][2],X[N],Y[N];
ll ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) X[i]=x[i],Y[i]=y[i];
	sort(X+1,X+n+1);
	sort(Y+1,Y+n+1);
	int m=(n+1)/2,cx=X[m],cy=Y[m],fl=0;
	int dx=X[m+1]-X[m],dy=Y[m+1]-Y[m];
	//cout<<dx<<' '<<dy<<endl;
	if (n&1){
		dx=min(dx,X[m]-X[m-1]);
		dy=min(dy,Y[m]-Y[m-1]);
	}
	For(i,1,n){
		ans+=abs(cx-x[i])+abs(cy-y[i]);
		++cnt[x[i]<=cx][y[i]<=cy];
		if (x[i]==cx&&y[i]==cy) fl=1;
	}
	//cout<<ans<<' '<<dx<<' '<<dy<<endl;
	//cout<<ans<<' '<<cx<<' '<<cy<<endl;
	if (cnt[0][0]&&cnt[0][1])
		if (n%2==0||fl) ans-=min(dx,dy);
	printf("%lld\n",ans*2);
} 
/*
n:
(00+11,01+10):0 
(00+01+10+11):min(dx,dy) 

n
(00+11,01+10):0
(00+01+10+11): 
*/