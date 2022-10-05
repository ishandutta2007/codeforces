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
const int MOD=23068673;
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),k=read();
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
int a[1<<22];
signed main(){
	fz(i,1,n)	a[read()]=1;
	for(int i=0;i<(1<<21);i++)	rev[i]=(rev[i>>1]>>1)|((i&1)<<20);
	NTT(1<<21,a,1);
	for(int i=0;i<(1<<21);i++)	a[i]=qpow(a[i],k,MOD);
	NTT(1<<21,a,-1);
	for(int i=0;i<(1<<21);i++)	if(a[i]!=0)	cout<<i<<" ";
	return 0;
}