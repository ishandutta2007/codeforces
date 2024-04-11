//Coded by tzc_wk
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
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
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
int a,b,c,d,e,f;
/*
aaaa -> 0 0 0 0 0 0
aaab -> 0 0 1 0 1 1
aaba -> 0 1 0 1 0 1
aabb -> 0 1 1 1 1 0
abaa -> 1 0 0 1 1 0
abab -> 1 0 1 1 0 1
abba -> 1 1 0 0 1 1
abbb -> 1 1 1 0 0 0

x4+x5+x6+x7=a      1
x2+x3+x6+x7=b      2
x1+x3+x5+x7=c      3
x2+x3+x4+x5=d      4
x1+x3+x4+x6=e      5
x1+x2+x5+x6=f      6

x2+x6-x3-x7=f-c		6-3
x2+x3-x6-x7=d-a		4-1
2(x2-x7)=f-c+d-a
2(x6-x3)=f-c-(d-a)
x2+x3-x4-x5=b-a		2-1
x2-x3-x4+x5=f-e		6-5
2(x2-x4)=b-a+f-e
2(x3-x5)=b-a-(f-e)
x2+x4-x1-x7=d-c		4-3
x1+x4-x2-x7=e-b		5-2
2(x4-x7)=d-c+e-b
2(x2-x1)=d-c-(e-b)
x1+x3-x4-x6=c-a
x1+x3+x4+x6=e
2(x1+x3)=c-a+e
*/
char s[1000005][4];
signed main(){
	cin>>a>>b>>c>>d>>e>>f;
	if((f-c+d-a)%2!=0)	return puts("-1"),0;
	if((b-a+f-e)%2!=0)	return puts("-1"),0;
	if((d-c+e-b)%2!=0)	return puts("-1"),0;
	if((c-a+e)%2!=0)	return puts("-1"),0;
	fz(x2,0,100000){
		int x7=x2-(f-c+d-a)/2;
		int x4=x2-(b-a+f-e)/2;
		int x1=x2-(d-c-e+b)/2;
		int x3=(c-a+e)/2-x1;
		int x6=(f-c-(d-a))/2+x3;
		int x5=x3-(b-a-(f-e))/2;
//		cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<" "<<x6<<" "<<x7<<endl;
		if(x1<0||x2<0||x3<0||x4<0||x5<0||x6<0||x7<0)	continue;
		int j=0;
		cout<<x1+x2+x3+x4+x5+x6+x7<<endl;
		fz(i,1,x1)	s[++j][0]='a',s[j][1]='a',s[j][2]='a',s[j][3]='b';
		fz(i,1,x2)	s[++j][0]='a',s[j][1]='a',s[j][2]='b',s[j][3]='a';
		fz(i,1,x3)	s[++j][0]='a',s[j][1]='a',s[j][2]='b',s[j][3]='b';
		fz(i,1,x4)	s[++j][0]='a',s[j][1]='b',s[j][2]='a',s[j][3]='a';
		fz(i,1,x5)	s[++j][0]='a',s[j][1]='b',s[j][2]='a',s[j][3]='b';
		fz(i,1,x6)	s[++j][0]='a',s[j][1]='b',s[j][2]='b',s[j][3]='a';
		fz(i,1,x7)	s[++j][0]='a',s[j][1]='b',s[j][2]='b',s[j][3]='b';
		fz(i,1,x1+x2+x3+x4+x5+x6+x7)	cout<<s[i][0];puts("");
		fz(i,1,x1+x2+x3+x4+x5+x6+x7)	cout<<s[i][1];puts("");
		fz(i,1,x1+x2+x3+x4+x5+x6+x7)	cout<<s[i][2];puts("");
		fz(i,1,x1+x2+x3+x4+x5+x6+x7)	cout<<s[i][3];puts("");
		return 0;
	}
	puts("-1");
	return 0;
}