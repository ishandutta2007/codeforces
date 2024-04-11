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
const int mo=998244353,M=16;
int n,m,a[35],x[10],y[10];
int f[31][M][M][M][M][2][2];
bool v[31][M][M][M][M][2][2];
int F(int bit,int JW1,int JW2,int JW3,int JW4,int fl1,int fl2){
	if (bit==30) return !JW1&&!JW2&&!JW3&&!JW4&&fl1&&fl2;
	if (v[bit][JW1][JW2][JW3][JW4][fl1][fl2])
		return f[bit][JW1][JW2][JW3][JW4][fl1][fl2];
	v[bit][JW1][JW2][JW3][JW4][fl1][fl2]=1;
	int &ans=f[bit][JW1][JW2][JW3][JW4][fl1][fl2];
	For(sta,0,(1<<n)-1){
		int NJW1=JW1,NJW2=JW2,NJW3=JW3,NJW4=JW4;
		For(i,1,n) if (sta&(1<<(i-1))){
			if (x[i]<=0) NJW1-=x[i];
			if (y[i]<=0) NJW2-=y[i];
			if (x[i]>=0) NJW3+=x[i];
			if (y[i]>=0) NJW4+=y[i];
		}
		if (((NJW1^NJW3)&1)||((NJW2^NJW4)&1)) continue;
		int nfl1=((NJW3&1)==a[bit]?fl1:(NJW3&1)<a[bit]);
		int nfl2=((NJW4&1)==a[bit]?fl2:(NJW4&1)<a[bit]);
		NJW1/=2; NJW2/=2; NJW3/=2; NJW4/=2;
		ans=(ans+F(bit+1,NJW1,NJW2,NJW3,NJW4,nfl1,nfl2))%mo;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,0,29) a[i]=(m>>i)&1;
	bool fl1=0,fl2=0,fl3=0,fl4=0;
	For(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		fl1|=(x[i]<0); fl2|=(x[i]>0);
		fl3|=(y[i]<0); fl4|=(y[i]>0);
	}
	if (!fl1||!fl2||!fl3||!fl4)	return puts("0"),0;
	printf("%d\n",(F(0,0,0,0,0,1,1)+mo-1)%mo);
}