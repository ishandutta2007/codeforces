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
int n,m,s1,cnt[65536];
ll a[55],x,ans[55];
void insert(ll x){
	Rep(i,m-1,0)
		if (x&(1ll<<i))
			if (!a[i]){
				a[i]=x;
				break;
			}
			else
				x^=a[i];
}
int Count(ll x){
	return cnt[x&65535]+
		   cnt[(x>>16)&65535]+
		   cnt[(x>>32)&65535]+
		   cnt[(x>>48)&65535];
}
void get_que(ll *q){
	static ll q1[1<<16];
	static ll q2[1<<16];
	int m=(*q)/2,l1=m,l2=(*q)-m;
	memset(q1,0,sizeof(q1));
	memset(q2,0,sizeof(q2));
	For(i,0,(1<<l1)-1) For(j,0,l1-1)
		if (i&(1<<j)) q1[i]^=q[j+1];
	For(i,0,(1<<l2)-1) For(j,0,l2-1)
		if (i&(1<<j)) q2[i]^=q[j+1+l1];
	For(i,0,(1<<l1)-1) For(j,0,(1<<l2)-1)
		++ans[Count(q1[i]^q2[j])];
}
void axiba1(){
	static ll q[55];
	For(i,0,m-1) if (a[i]) q[++*q]=a[i];
	get_que(q);
}
void axiba2(){
	static ll q[55],f[55];
	Rep(i,m-1,0) if (a[i])
		For(j,i+1,m-1) if (a[j]&(1ll<<i))
			a[j]^=a[i];
	For(i,0,m-1) if (!a[i]){
		q[++*q]=1ll<<i;
		For(j,0,m-1) if (a[j]&(1ll<<i)) q[*q]|=1ll<<j;
	}
	get_que(q);
	int top=*q;
	memcpy(q,ans,sizeof(q));
	memset(ans,0,sizeof(ans));
	For(i,0,m){
		memset(f,0,sizeof(f)); f[0]=1;
		For(j,1,m) Rep(k,m-1,0)
			f[k+1]+=((j<=i)?-f[k]:f[k]);
		For(j,0,m) ans[j]+=(q[i]%mo)*(f[j]%mo);
		//cout<<q[i]<<' '<<f[0]<<' '<<ans[0]<<endl;
	}
	For(i,0,m) ans[i]=(ans[i]%mo+mo)%mo;
	For(i,0,m) For(j,1,top)
		ans[i]=1ll*ans[i]*(mo+1)/2%mo;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,0,(1<<16)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,1,n) scanf("%lld",&x),insert(x);
	For(i,0,m-1) if (a[i]) s1++;
	if (s1<=27) axiba1();
	else axiba2();
	int val=1;
	For(i,s1+1,n) val=2ll*val%mo;
	For(i,0,m) printf("%d ",1ll*ans[i]%mo*val%mo);
}