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
int a[10005],b[10005],c[10005];
char s[10005],t[10005];
signed main(){
	cin>>s+1;
	int n=strlen(s+1),tmp=n;
	cout<<"? ";
	fz(i,0,25){
		fz(j,0,25){
			fz(k,0,25){
				if(tmp){
					tmp--;
					putchar(i+'a');
				}
			}
		}
	}
	puts("");
	fflush(stdout);
	cin>>t+1;
	fz(i,1,n)	a[i]=t[i]-'a';
	tmp=n;
	cout<<"? ";
	fz(i,0,25){
		fz(j,0,25){
			fz(k,0,25){
				if(tmp){
					tmp--;
					putchar(j+'a');
				}
			}
		}
	}
	puts("");
	fflush(stdout);
	cin>>t+1;
	fz(i,1,n)	b[i]=t[i]-'a';
	tmp=n;
	cout<<"? ";
	fz(i,0,25){
		fz(j,0,25){
			fz(k,0,25){
				if(tmp){
					tmp--;
					putchar(k+'a');
				}
			}
		}
	}
	puts("");
	fflush(stdout);
	cin>>t+1;
	fz(i,1,n)	c[i]=t[i]-'a';
	fz(i,1,n)	t[a[i]*676+b[i]*26+c[i]+1]=s[i];
	cout<<"! "<<t+1<<endl;
	return 0;
}