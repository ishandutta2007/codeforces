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
#define int long long
const int N=60;
int n,a[N],b[N];
int ans1[N],ans2[N];
int tms[N],fl;
char s[N];
const ll mo1=3000000019ll;
const ll mo2=3000000037ll;
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
ll CRT(int ans1,int ans2){
	ll v1=1ll*ans1*power(mo2,mo1-2,mo1)%mo1*mo2;
	ll v2=1ll*ans2*power(mo1,mo2-2,mo2)%mo2*mo1;
	ll ans=(1ull*v1+1ull*v2)%(1ll*mo1*mo2);
	assert(ans%mo1==ans1);
	assert(ans%mo2==ans2);
	return ans;
}
struct solver{
	int t[N][N],mo;
	int op[N*N],opx[N*N],opy[N*N];
	void gauss(int n){
		For(i,0,n-1){
			int p=-1;
			For(j,i,n) if (t[j][i]) p=j;
			assert(p!=-1);
			if (p!=i){
				For(j,0,n)
					swap(t[i][j],t[p][j]);
				op[++*op]=-1;
				opx[*op]=i; opy[*op]=p;
			}
			int v=power(t[i][i],mo-2,mo);
			For(j,0,n) if (j!=i){
				int val=1ll*(mo-t[j][i])*v%mo;
				op[++*op]=val;
				opx[*op]=j; opy[*op]=i;
				For(k,0,n) t[j][k]=(t[j][k]+1ll*val*t[i][k])%mo;
			}
		}
	}
	void init(){
		int I2=(mo+1)/2; *op=0; 
		memset(t,0,sizeof(t));
		For(i,0,n-1){
			t[a[i]][i]=(t[a[i]][i]+I2)%mo;
			t[b[i]][i]=(t[b[i]][i]+I2)%mo;
		}
		For(i,0,n-1) t[i][i]=(t[i][i]+mo-1)%mo;
		gauss(n-1);
	}
	void solve(char *s,int p,int *ans){
		int I2=(mo+1)/2;
		For(i,0,n) ans[i]=0;
		For(i,0,n-1) if (s[i]=='R'){
			ans[a[i]]=(ans[a[i]]+mo-I2)%mo;
			ans[b[i]]=(ans[b[i]]+I2)%mo;
		}
		ans[0]=(ans[0]+1)%mo;
		ans[p]=(ans[p]+mo-1)%mo;
		For(i,0,n-1) ans[i]=(mo-ans[i])%mo;
		For(i,1,*op)
			if (op[i]==-1) swap(ans[opx[i]],ans[opy[i]]);
			else ans[opx[i]]=(ans[opx[i]]+1ll*op[i]*ans[opy[i]])%mo;
		For(i,0,n-1) ans[i]=1ll*ans[i]*power(t[i][i],mo-2,mo)%mo;
	}
}S1,S2;
signed main(){
	scanf("%lld",&n);
	For(i,0,n-2) scanf("%lld%lld",&a[i],&b[i]);
	For(i,0,n-2) --a[i],--b[i];
	a[n-1]=b[n-1]=n-1;
	S1.mo=mo1; S2.mo=mo2;
	S1.init(); S2.init();
	int Q,p;
	scanf("%lld",&Q);
	while (Q--){
		scanf("%lld%s",&p,s);
		p=p-1; s[n-1]='B'; fl=0;
		S1.solve(s,p,ans1); S2.solve(s,p,ans2);
		For(i,0,n-1) tms[i]=CRT(ans1[i],ans2[i]);
		For(i,0,n-1) if (((s[i]=='R')+tms[i])%2==1) fl=1;
		For(i,0,n-1) if (tms[i]){
			int x=i,fll=0;
			For(j,1,n){
				if (x==p) fll=1;
				x=(tms[x]&1?b[x]:a[x]);
			}
			if (!fll) fl=1;
		}
		if (fl) puts("-1");
		else{
			ll ans=0;
			For(i,0,n-1) ans+=tms[i];
			printf("%lld\n",ans);
		}
	}
}