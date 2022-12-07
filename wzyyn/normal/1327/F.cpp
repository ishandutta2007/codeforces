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
const int N=500005;
const int mo=998244353;
int s[N],f[N],le[N];
int n,K,m,l[N],r[N],v[N];
int F(int B){
	memset(s,0,sizeof(s));
	memset(f,0,sizeof(f));
	For(i,1,m) if (v[i]&B)
		s[l[i]]++,s[r[i]+1]--;
	For(i,1,n) le[i]=0;
	For(i,1,m) if (!(v[i]&B))
		le[r[i]]=max(le[r[i]],l[i]);
	int pos=0,ans=f[0]=1;
	For(i,1,n){
		s[i]+=s[i-1];
		if (!s[i]) f[i]=ans,ans=2ll*ans%mo;
		for (;pos<le[i];ans=(ans+mo-f[pos++])%mo);
	}
	//cout<<B<<' '<<ans<<endl;
	return ans;
}
int main(){
	int ans=1;
	scanf("%d%d%d",&n,&K,&m);
	For(i,1,m) scanf("%d%d%d",&l[i],&r[i],&v[i]);
	For(i,0,K-1) ans=1ll*ans*F(1<<i)%mo;
	printf("%d\n",ans);
}