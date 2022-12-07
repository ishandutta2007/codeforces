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
const int mo=998244353;
const int N=1000005;
int n,m,a[N],b[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	int pos=n,ans=1;
	Rep(i,m,1){
		int la=0;
		for (;pos&&b[i]<=a[pos];--pos)
			if (b[i]==a[pos]&&!la) la=pos;
		//cout<<i<<' '<<la<<' '<<pos<<endl;
		if (!la) ans=0;
		else if (i!=1) ans=1ll*ans*(la-pos)%mo;
	}
	if (pos!=0) ans=0;
	cout<<ans<<endl;
}