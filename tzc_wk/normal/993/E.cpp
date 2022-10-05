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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
const double Pi=acos(-1.0);
struct comp{
	double x,y;
	comp(){x=y=0;}
	comp(double a,double b){x=a;y=b;}
	comp operator +(comp c){return comp(x+c.x,y+c.y);}
	comp operator -(comp c){return comp(x-c.x,y-c.y);}
	comp operator *(comp c){return comp(x*c.x-y*c.y,x*c.y+y*c.x);}
} a[1<<20],b[1<<20];
int rev[1<<20];
inline void FFT(int len,comp *a,int type){
	for(int i=0;i<len;i++){
		if(i<rev[i])	swap(a[i],a[rev[i]]);
	}
	for(int mid=1;mid<len;mid<<=1){
		comp W(cos(Pi/mid),type*sin(Pi/mid));
		for(int j=0;j<len;j+=mid<<1){
			comp w(1,0);
			for(int k=0;k<mid;k++){
				comp x=a[j+k],y=w*a[j+mid+k];
				a[j+k]=x+y;
				a[j+mid+k]=x-y;
				w=w*W;
			}
		}
	}
}
int n=read(),x=read(),cnt[300005],sum[300005];
signed main(){
	fz(i,1,n){
		int val=read();
		if(val<x)	sum[i]=sum[i-1]+1;
		else		sum[i]=sum[i-1];
		cnt[sum[i]]++;;
	}
	cnt[0]++;;
	int N=1,lg=0;
	while(N<=n*2)	N<<=1,lg++;
	for(int i=0;i<N;i++)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<=n;i++)	a[i]=comp(cnt[i],0),b[i]=comp(cnt[n-i],0);
	FFT(N,a,1);
	FFT(N,b,1);
	for(int i=0;i<N;i++)	a[i]=a[i]*b[i];
	FFT(N,a,-1);
	int ans=0,lst=0;
	for(int i=1;i<=n;i++){
		if(sum[i]!=sum[i-1])	lst=i;
		ans+=i-lst;
	}
	cout<<ans<<" ";
	for(int i=n-1;~i;i--)	cout<<(int)(a[i].x/N+0.5)<<" ";
	return 0;
}