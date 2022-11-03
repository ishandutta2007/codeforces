#include<queue>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<ctime>
#define ll long long
#define mk make_pair
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll mod=1e9+7,N=1000010;
struct data{	ll mnx,mxx,mny,mxy,nx,ny,id;	}q[N];
ll ans,mnx,mxx,mny,mxy,n,h,w,nowx,nowy,ons_x,ons_y,tot;
char s[N];
bool cmp(ll x){	return	((q[x].mnx+q[x].mxx>=h)||(q[x].mny+q[x].mxy>=w));	}
int main(){
	n=read();	h=read();	w=read();
	scanf("%s",s+1);
	For(i,1,n){
		ll t=i;
		if (s[t]=='L')	nowy--;
		if (s[t]=='R')	nowy++;
		if (s[t]=='U')	nowx--;
		if (s[t]=='D')	nowx++;
		mnx=max(mnx,-nowx);
		mxx=max(mxx,nowx);
		mny=max(mny,-nowy);
		mxy=max(mxy,nowy);
		if (i==n)	ons_x=nowx,
					ons_y=nowy;
		if ((mnx>q[tot].mnx)||(mny>q[tot].mny)||(mxx>q[tot].mxx)||(mxy>q[tot].mxy)){
			q[++tot].id=i;
			q[tot].mnx=mnx;
			q[tot].mxx=mxx;
			q[tot].mny=mny;
			q[tot].mxy=mxy;
			q[tot].nx=nowx;
			q[tot].ny=nowy;
			if (cmp(tot))	break;
		}
	}ll p=1;
	while(!cmp(tot)){
		bool fl=0;
		while(p<=tot){
			ll t1=-q[p].nx-ons_x,
			   t2=q[p].nx+ons_x,
			   t3=-q[p].ny-ons_y,
			   t4=q[p].ny+ons_y;
			if (t1>q[tot].mnx||t2>q[tot].mxx||t3>q[tot].mny||t4>q[tot].mxy){
				q[tot+1]=(data){max(q[tot].mnx,t1),max(q[tot].mxx,t2),max(q[tot].mny,t3),max(q[tot].mxy,t4),t2,t4,q[p].id+n};	p++;	tot++;
				fl=1;
				break;
			}else	p++;
		}if (!fl)	return puts("-1"),0;
	}
	For(i,1,tot){
		if (q[i].mnx!=q[i-1].mnx)	ans+=q[i].id%mod*(w-q[i].mny-q[i].mxy)%mod;
		if (q[i].mxx!=q[i-1].mxx)	ans+=q[i].id%mod*(w-q[i].mny-q[i].mxy)%mod;
		if (q[i].mny!=q[i-1].mny)	ans+=q[i].id%mod*(h-q[i].mnx-q[i].mxx)%mod;
		if (q[i].mxy!=q[i-1].mxy)	ans+=q[i].id%mod*(h-q[i].mnx-q[i].mxx)%mod;
		if (cmp(i))	break;
	}writeln(ans%mod);
}