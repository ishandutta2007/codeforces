/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
const int MOD=998244353;
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int rev[1<<22];
inline void NTT(int len,int *a,int type){
	for(int i=0;i<len;i++){
		if(i<rev[i])	swap(a[i],a[rev[i]]);
	}
	for(int mid=1;mid<len;mid<<=1){
		int W=qpow((type==1)?3:qpow(3,MOD-2,MOD),(MOD-1)/(mid<<1),MOD);
		for(int j=0;j<len;j+=mid*2){
			int w=1;
			for(int k=0;k<mid;k++){
				int x=a[j+k],y=w*a[j+mid+k]%MOD;
				a[j+k]=(x+y)%MOD;
				a[j+mid+k]=(x-y+MOD)%MOD;
				w=w*W%MOD;
			}
		}
	}
}
int f[1<<22],ff[1<<22];
int a[1<<22],b[1<<22],bin_pow[1<<22];
inline void init(){
	f[0]=1,bin_pow[0]=1;
	for(int i=1;i<=(1<<21);i++)	f[i]=f[i-1]*i%MOD,bin_pow[i]=bin_pow[i-1]*2%MOD;
	ff[1<<21]=qpow(f[1<<21],MOD-2,MOD);
	for(int i=(1<<21)-1;i>=0;i--)	ff[i]=ff[i+1]*(i+1)%MOD;
}
inline int C(int x,int y){
	if(x<y)	return 0;
	return f[x]*ff[y]%MOD*ff[x-y]%MOD;
}
int n=read(),k=read(),cnt[1<<22],ans[1<<22];
signed main(){
	init();
	int N=1,lg=0;
	while(N<=(n<<1))	N<<=1,lg++;
	fz(i,0,N-1)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	fz(i,1,n)	cnt[read()]++;
	int inv=qpow(N,MOD-2,MOD);
	fz(i,1,k){
		int val=read(),num1=0,num2=0;
		fz(j,1,val-1){
			if(cnt[j]==1)		num1++;
			else if(cnt[j]>=2)	num2++;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		fz(j,0,N-1){
			a[j]=bin_pow[j]*C(num1,j)%MOD;
			b[j]=C(num2*2,j);
		}
		NTT(N,a,1);
		NTT(N,b,1);
		fz(j,0,N-1){
			a[j]=a[j]*b[j]%MOD;
		}
		NTT(N,a,-1);
		fz(j,0,N-1){
			ans[j+val+1]=(ans[j+val+1]+a[j]*inv%MOD)%MOD;
		}
	}
	int T=read();
	while(T--)	print(ans[read()>>1]),eoln;
	return 0;
}