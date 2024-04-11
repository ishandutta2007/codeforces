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
int a[N],n;
ll s[N],S[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
ll F(ll a,ll b,ll c,ll n){
	if (n<0) return 0;
	if (a>=c) return (n+1)*n/2*(a/c)+F(a%c,b,c,n);
	if (b>=c) return (n+1)*(b/c)+F(a,b%c,c,n);
	if (c==1) return 0;
	ll m=(a*n+b)/c;
	return (n+1)*m-F(c,c-b-1,a,m-1);
}
/*
(ax+b)/c
For(i,0,m-1) (ci+c-1-b)/a
*/
void init(){
	static int q1[25],q2[25];
	int top=0,x;
	For(i,1,n){
		scanf("%d",&x);
		q1[++top]=x; q2[top]=1;
		Rep(j,top-1,1) q1[j]=gcd(q1[j+1],q1[j]);
		int tmp=top; top=1;
		For(j,2,tmp)
			if (q1[j]==q1[top])
				q2[top]+=q2[j];
			else{
				q1[++top]=q1[j];
				q2[top]=q2[j]; 
			}
		For(j,1,top) a[q1[j]]+=q2[j];
	}
	For(i,1,N-1){
		s[i]=s[i-1]+a[i];
		S[i]=S[i-1]+1ll*i*a[i];
	}
}
ll check(ll v){
	int p=1; v++;
	ll ans=1ll*n*(n+1)/2;
	For(i,1,N-1)
		if (a[i]&&S[i]>=v)
			for (;;++p){
				if (!a[p]) continue;
				ll vl=max(S[p-1]+v,S[i-1]+i);
				ll vr=min(S[p]-1+v,S[i]);
				//cout<<i<<' '<<p<<' '<<vl<<' '<<vr<<endl;
				vl+=(i-(vl-S[i-1])%i)%i;
				vr-=(vr-S[i-1])%i;
				//cout<<i<<' '<<p<<' '<<vl<<' '<<vr<<endl;
				if (vl<=vr){
					ans-=1ll*(vr-vl+i)/i*(s[p-1]+1);
					//cout<<ans<<endl;
					ans-=F(i,vl-v-S[p-1],p,(vr-vl)/i);
				}
				if (S[p]-1+v>=S[i]) break;
			}
	//cout<<v-1<<' '<<ans<<endl;
	return ans;
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n);
	init(); n=1ll*n*(n+1)/2;
	ll l=1,r=1ll*n*N,ans=-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)>=(1ll*n*(n+1)+2)/4)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}