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
const double Pi=acos(-1.0);
struct comp{
	double x,y;
	comp(){x=y=0;}
	comp(double a,double b){x=a;y=b;}
	inline comp operator +(comp c){return comp(x+c.x,y+c.y);}
	inline comp operator -(comp c){return comp(x-c.x,y-c.y);}
	inline comp operator *(comp c){return comp(x*c.x-y*c.y,x*c.y+y*c.x);}
} a[1<<20],b[1<<20],p[1<<20];
int rev[1<<20];
inline void FFT(int len,comp* a,int type){
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
int N=1,n=read(),m=read(),k=read();
char s[200005],t[200005];
int cnt[1<<20];
inline void go(char c){
	int lst=-1e9;
	for(int i=0;i<N;i++)	a[i]=comp(0,0),b[i]=comp(0,0);
	fz(i,0,n-1){
		if(s[i]==c)	lst=i;
		if((i-lst)<=k)	a[i]=comp(1,0);
	}
	lst=1e9;
	fd(i,n-1,0){
		if(s[i]==c)	lst=i;
		if((lst-i)<=k)	a[i]=comp(1,0);
	}
	fz(i,0,m-1){
		if(t[i]==c){
			b[m-i-1]=comp(1,0);
		}
	}
	FFT(N,a,1);
	FFT(N,b,1);
	for(int i=0;i<N;i++)	a[i]=a[i]*b[i];
	FFT(N,a,-1);
	for(int i=0;i<n;i++)	cnt[i]+=int(a[i].x/N+0.5);
}
int main(){
	cin>>s>>t;
	int num=0;
	while(N<=n+m)	N<<=1,num++;
	for(int i=0;i<N;i++)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(num-1));
	int ans=0;
	go('A');go('C');go('G');go('T');
	fz(i,0,n-1)	if(cnt[i]==m)	ans++;
	print(ans);
	return 0;
}