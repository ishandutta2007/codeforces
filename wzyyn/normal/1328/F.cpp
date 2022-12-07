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
const int N=200005;
int n,k,a[N];
ll S[N],ans;
void upd(int l,int r){
	//cout<<l<<' '<<r<<endl;
	ll cl=1ll*(a[l]-1)*(l-1)-S[l-1];
	ll cr=-1ll*(a[l]+1)*(n-r)+(S[n]-S[r]);
	//cout<<cl<< '
	if (r-l+1>=k) ans=min(ans,0ll);
	else{
		if (r>=k) ans=min(ans,cl+k-(r-l+1));
		if (n-l+1>=k) ans=min(ans,cr+k-(r-l+1));
		ans=min(ans,cl+cr+k-(r-l+1));
	}
}
int main(){
	ans=1ll<<60;
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) S[i]=S[i-1]+a[i];
	int las=1;
	For(i,2,n+1)
		if (i==n+1||a[i]!=a[i-1])
			upd(las,i-1),las=i;
	printf("%lld\n",ans);
}