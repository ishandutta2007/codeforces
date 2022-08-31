//CF1450H2
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<20;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
int n,q,b0,b1,k0,k1,ans;
int fac[N],ifac[N];
char s[N],ch[5];
int C(int x,int y){
	if(y<0||y>x)
		return 0;
	return mul(fac[x],mul(ifac[y],ifac[x-y]));
}
struct node1{
	int k,b,x;
	void ini(int K,int B){
		int i;
		k=K,b=B;
		x=0;
		for(i=0;i<=b;i=i+1)
			ad(x,C(k,i));
	}
	void inck(){
		x=mul(x,2);
		ad(x,MO-C(k,b));
		k++;
	}
	void deck(){
		k--;
		ad(x,C(k,b));
		x=mul(x,(MO+1)/2);
	}
	void incb(){
		b++;
		ad(x,C(k,b));
	}
	void decb(){
		ad(x,MO-C(k,b));
		b--;
	}
}P,Q;
int D(int k,int b){
	if(b<0)
		return 0;
	if(k==0)
		return 1;
	if(b&1)
		return MO-C(k-1,b);
	return C(k-1,b);
}
int kk,bb;
int solve(int k,int b){
	while(kk<k){
		P.inck();
		Q.inck();
		kk++;
	}
	while(kk>k){
		P.deck();
		Q.deck();
		kk--;
	}
	while(bb<b){
		P.incb();
		Q.incb();
		bb++;
	}
	while(bb>b){
		P.decb();
		Q.decb();
		bb--;
	}
	if(!k){
		if(b&1)
			return 0;
		return max(b,-b);
	}
	int x,y,z,w,s,t;
	x=mul(b+MO,P.x);
	y=mul(k,Q.x);
	ad(x,MO-y);
	z=mul(b+MO,fpow(2,k));
	w=mul(k,fpow(2,k-1));
	ad(z,MO-w);
	s=mul(x,2);
	ad(s,MO-z);
	x=mul(b+MO,D(k,b));
	y=mul(k,D(k-1,b-1));
	ad(x,y);
	z=mul(b+MO,D(k,k));
	w=mul(k,D(k-1,k-1));
	ad(z,w);
	t=mul(x,2);
	ad(t,MO-z);
	if(b&1)
		t=MO-t;
	ad(s,t);
	return mul(s,fpow(fpow(2,k+1)));
}
int main()
{
	int i,k,b;
	scanf("%d%d%s",&n,&q,s+1);
	fac[0]=1;
	for(i=1;i<=n;i=i+1)
		fac[i]=mul(fac[i-1],i);
	ifac[n]=fpow(fac[n]);
	for(i=n;i>=1;i=i-1)
		ifac[i-1]=mul(ifac[i],i);
	for(i=1;i<=n;i=i+1){
		if(s[i]=='b'){
			if(i&1)
				b1++;
			else
				b0++;
		}
		if(s[i]=='?'){
			if(i&1)
				k1++;
			else
				k0++;
		}
	}
	k=k0+k1,b=b0-b1+k0;
	P.ini(k,b),Q.ini(k-1,b-1);
	kk=k,bb=b;
	printf("%d\n",solve(k,b));
	while(q--){
		scanf("%d%s",&i,ch);
		if(s[i]=='b'){
			if(i&1)
				b1--;
			else
				b0--;
		}
		if(s[i]=='?'){
			if(i&1)
				k1--;
			else
				k0--;
		}
		s[i]=ch[0];
		if(s[i]=='b'){
			if(i&1)
				b1++;
			else
				b0++;
		}
		if(s[i]=='?'){
			if(i&1)
				k1++;
			else
				k0++;
		}
		k=k0+k1,b=b0-b1+k0;
		printf("%d\n",solve(k,b));
	}
	return 0;
}