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
int n,m,a[N],q[55];
int phi(int x){
	int y=x;
	for (int i=2;1ll*i*i<=y;i++)
		if (y%i==0){
			x-=x/i;
			for (;y%i==0;y/=i);
		}
	if (y!=1)
		x-=x/y;
	return x;
}
int moo(int x,int y,int mo){
	ll ans=1ll*x*y;
	if (ans<=20) return ans;
	return ans%mo+(ans%mo<=20?mo:0);
} 
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=moo(x,x,mo))
		if (y&1) s=moo(s,x,mo);
	return s;
}
int F(int l,int r,int m){
	if (m>*q) return 0;
	if (l>r) return 1;
	return power(a[l],F(l+1,r,m+1),q[m]);
}
int main(){
	int mo;
	scanf("%d%d",&n,&m); mo=m;
	For(i,1,n) scanf("%d",&a[i]);
	for (q[++*q]=m;m!=1;q[++*q]=m=phi(m));
	For(i,1,10) q[++*q]=1;
	//For(i,1,*q) cout<<q[i]<<endl;
	scanf("%d",&m);
	while (m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",F(l,r,1)%mo);
	}
}