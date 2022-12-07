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
void UPD(ll &x,ll y){
	(x+=y)>=mo?x-=mo:233;
}
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
void axiba1(){
	static int q[55];
	static ll q1[1<<16];
	static ll q2[1<<16];
	For(i,0,m-1) if (a[i]) q[++*q]=i;
	int m=(*q)/2,l1=m,l2=(*q)-m;
	memset(q1,0,sizeof(q1));
	memset(q2,0,sizeof(q2));
	For(i,0,(1<<l1)-1) For(j,0,l1-1)
		if (i&(1<<j)) q1[i]^=a[q[j+1]];
	For(i,0,(1<<l2)-1) For(j,0,l2-1)
		if (i&(1<<j)) q2[i]^=a[q[j+1+l1]];
	For(i,0,(1<<l1)-1) For(j,0,(1<<l2)-1)
		++ans[Count(q1[i]^q2[j])];
}
void axiba2(){
	static int id[55];
	static ll f[55][1<<16];
	int top=0,pre=0,suf=1;
	For(i,0,m-1) if (a[i])
		For(j,i+1,m-1) if (a[j]&(1ll<<i)) a[j]^=a[i];
	For(i,0,m-1) if (!a[i]) id[i]=top++;
	f[0][0]=1;
	For(i,0,m-1) if (a[i]){
		int sta=0;
		For(j,0,i-1)
			if (a[i]&(1ll<<j))
				sta|=1<<id[j];
		Rep(j,i,0) For(k,0,(1<<top)-1)
			f[j+1][k^sta]+=f[j][k];
	}
	For(i,0,m) For(j,0,(1<<top)-1)
		ans[i+Count(j)]+=f[i][j];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,0,(1<<16)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,1,n) scanf("%lld",&x),insert(x);
	For(i,0,m-1) if (a[i]) s1++;
	if (s1<=20) axiba1();
	else axiba2();
	int val=1;
	For(i,s1+1,n) val=2ll*val%mo;
	For(i,0,m) printf("%d ",1ll*ans[i]%mo*val%mo);
}
/*
kxor1m 

k<=l1,2^l1O(2^l1) 
k>=l1,<=l2 
			2^l2O(2^l2*(m-l1-l2)*l2) 
			2^(m-l1-l2)2^(m-l1-l2)O(4^(m-l1-l2)*l1)
			
l1=25,l2=18 
*/