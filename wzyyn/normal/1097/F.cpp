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
int n,m,cnt[100000],mu[7005];
struct Bitset{
	uint a[230];
	Bitset(){
		memset(a,0,sizeof(a));
	}
	Bitset operator &(const Bitset &b)const{
		Bitset r;
		for (int i=0;i<225;i+=4){
			r.a[i+0]=a[i+0]&b.a[i+0];
			r.a[i+1]=a[i+1]&b.a[i+1];
			r.a[i+2]=a[i+2]&b.a[i+2];
			r.a[i+3]=a[i+3]&b.a[i+3];
		}
		return r;
	}
	Bitset operator ^(const Bitset &b)const{
		Bitset r;
		for (int i=0;i<225;i+=4){
			r.a[i+0]=a[i+0]^b.a[i+0];
			r.a[i+1]=a[i+1]^b.a[i+1];
			r.a[i+2]=a[i+2]^b.a[i+2];
			r.a[i+3]=a[i+3]^b.a[i+3];
		}
		return r;
	}
	int count()const{
		int s=0;
		for (int i=0;i<225;i+=4){
			s^=cnt[(a[i+0]>>16)]^cnt[(a[i+0]&65535)];
			s^=cnt[(a[i+1]>>16)]^cnt[(a[i+1]&65535)];
			s^=cnt[(a[i+2]>>16)]^cnt[(a[i+2]&65535)];
			s^=cnt[(a[i+3]>>16)]^cnt[(a[i+3]&65535)];
		}
		return s;
	}
	void set(int x){
		a[x>>5]|=1u<<(x&31);
	}
};
Bitset I[7005];
Bitset Q[7005];
Bitset B[100005];
void init(){
	mu[1]=1;
	For(i,1,7000) For(j,2,7000/i) mu[i*j]^=mu[i];
	For(i,1,7000) if (mu[i])
		For(j,1,7000/i) Q[j].set(i*j);
	For(i,1,7000)
		For(j,1,7000/i)
			I[i*j].set(i);
	For(i,0,65535)
		cnt[i]=cnt[i/2]^(i&1);
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	while (m--){
		int tp,x,y,z;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==2||tp==3) scanf("%d",&z);
		if (tp==1) B[x]=I[y];
		if (tp==2) B[x]=B[y]^B[z];
		if (tp==3) B[x]=B[y]&B[z];
		if (tp==4) putchar((B[x]&Q[y]).count()?'1':'0');
	}
}