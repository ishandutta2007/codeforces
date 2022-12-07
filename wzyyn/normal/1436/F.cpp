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
const int N=100005;
const int mo=998244353;
int w0[N],wo[N],w1[N],w2[N];
int n,ans[N];
int power(int x,int y){
	int s=1;
	if (y<0) y+=mo-1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		w0[x]=(w0[x]+y)%(mo-1);
		wo[x]=(wo[x]+y)%mo;
		w1[x]=(w1[x]+1ll*x*y)%mo;
		w2[x]=(w2[x]+1ll*x*x%mo*y)%mo;
	}
	For(i,1,N-1)
		For(j,2,(N-1)/i){
			w0[i]=(w0[i]+w0[i*j])%(mo-1);
			wo[i]=(wo[i]+wo[i*j])%mo;
			w1[i]=(w1[i]+w1[i*j])%mo;
			w2[i]=(w2[i]+w2[i*j])%mo;
		}
	For(i,1,N-1){
		ans[i]=1ll*power(2,w0[i]-2)*(wo[i]+mo-1)%mo*w2[i]%mo;
		ans[i]=(ans[i]+(1ll*power(2,w0[i]-3)*(wo[i]+mo-2)+power(2,w0[i]-2))%mo*(1ll*w1[i]*w1[i]%mo+mo-w2[i]))%mo;
	}
	Rep(i,N-1,1)
		For(j,2,(N-1)/i)
			ans[i]=(ans[i]+mo-ans[i*j])%mo;
	cout<<ans[1]<<endl;
}