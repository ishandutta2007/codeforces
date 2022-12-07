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

ll a[1<<20];
int n,Q,rev[25],swp[25];
int TR(int x){
	Rep(i,n-1,0){
		int rem=x%(1<<(i+1));
		x-=rem;
		if (rev[i+1]) rem=(1<<(i+1))-1-rem;
		if (swp[i]) rem^=(1<<i);
		x+=rem;
	}
	return x;
}
ll qry(int p,int d,int x,int y){
	//cout<<p<<' '<<x<<' '<<y<<endl;
	x%=1<<d; y%=1<<d;
	if (x==0&&y==(1<<d)-1) return a[p];
	if (rev[d]){
		swap(x,y);
		x=(1<<d)-x-1;
		y=(1<<d)-y-1;
	}
	int mid=(1<<(d-1))-1;
	if (y<=mid) return qry(p*2+swp[d-1],d-1,x,y);
	if (x>mid) return qry(p*2+1-swp[d-1],d-1,x,y);
	return qry(p*2+swp[d-1],d-1,x,mid)+qry(p*2+1-swp[d-1],d-1,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1<<n,(2<<n)-1) scanf("%lld",&a[i]);
	Rep(i,(1<<n)-1,1) a[i]=a[i<<1]+a[i<<1|1];
	while (Q--){
		int tp,x,v;
		scanf("%d%d",&tp,&x);
		if (tp==1||tp==4) scanf("%d",&v);
		if (tp==1){
			x=TR(x-1)+(1<<n); a[x]=v;
			for (x>>=1;x;x>>=1)
				a[x]=a[x<<1]+a[x<<1|1];
		}
		else if (tp==2) rev[x]^=1;
		else if (tp==3) swp[x]^=1;
		else if (tp==4) printf("%lld\n",qry(1,n,x-1,v-1));
	}
}