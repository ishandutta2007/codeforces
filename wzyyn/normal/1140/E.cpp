#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 hfjskghsdjkfg
using namespace std;
const int mo=998244353;
int n,mx,ans=1;
int a[200005];
void solve(int st){
	int pre=st,suf=((n+st)%2==0?n:n-1);
	for (;pre<suf&&a[pre]==-1;)
		ans=1ll*ans*(mx-1)%mo,pre+=2;
	for (;pre<suf&&a[suf]==-1;)
		ans=1ll*ans*(mx-1)%mo,suf-=2;
	if (pre==suf){
		if (a[pre]==-1) ans=1ll*ans*mx%mo;
		return;
	}
	int pos=pre,f0=1,f1=0;
	for (pre+=2;pre<=suf;pre+=2){
		int nf0=1ll*(mx-1)*f1%mo;
		int nf1=(1ll*(mx-2)*f1+f0)%mo;
		f0=nf0; f1=nf1;
		if (a[pre]!=-1){
			if (a[pre]==a[pos]) ans=1ll*ans*f0%mo;
			else ans=1ll*ans*f1%mo;
			pos=pre; f0=1; f1=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&mx);
	For(i,1,n) scanf("%d",&a[i]);
	solve(1); solve(2);
	printf("%d\n",ans);
}