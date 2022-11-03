#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
using namespace std;
#define ll long long
#define maxn 100010
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
set<ll> g[maxn];
ll a[maxn],f[70][70],n,Q,L[maxn],R[maxn],bel[maxn],mp[maxn],pre[maxn],nxt[maxn],tot,cnt;
inline bool in(ll x,ll l,ll r){	return bel[x]>=l&&bel[x]<=r;	}
inline void change(ll x,ll v,ll ref){
	ll a=pre[x],b=nxt[x];
	bool fl,fl2,fl3;
	For(i,1,tot)	For(j,i,tot){
		fl=in(a,i,j),fl2=in(x,i,j),fl3=in(b,i,j);
		if (fl&&fl2&&!fl3)	f[i][j]+=ref*(x-a);
		if (fl3&&fl2&&!fl)	f[i][j]+=ref*(b-x);
	}
}
inline ll query(ll l,ll r){
	ll x=bel[l],y=bel[r],ans=0;
	if (x+1>=y){
		For(i,l,r){
			if (mp[a[i]])	ans+=i-mp[a[i]];
			mp[a[i]]=i;
		}
		For(i,l,r)	mp[a[i]]=0;
		return ans;
	}ans=f[x+1][y-1];
	FOr(i,R[x],l)	if (nxt[i]<=R[y-1]&&nxt[i])	ans+=nxt[i]-i;
	For(i,L[y],r)	if (pre[i]>=l)	ans+=i-pre[i];
	return ans;
}
int main(){
	n=read();	Q=read();	cnt=2000;
	For(i,1,n)	a[i]=read(),g[a[i]].insert(i);
	For(i,1,n)	bel[i]=(i-1)/cnt+1;
	tot=bel[n];
	For(i,1,tot)	L[i]=(i-1)*cnt+1,R[i]=min(n,i*cnt);
	For(i,1,n){
		pre[i]=mp[a[i]];
		mp[a[i]]=i;
	}memset(mp,0,sizeof mp);
	FOr(i,n,1){
		nxt[i]=mp[a[i]];
		mp[a[i]]=i;
	}memset(mp,0,sizeof mp);
	For(i,1,tot){
		ll ans=0;
		For(j,i,tot){
			For(k,L[j],R[j]){
				if (mp[a[k]])	ans+=(k-mp[a[k]]);
				mp[a[k]]=k;
			}f[i][j]=ans;
		}memset(mp,0,sizeof mp);
	}
	while(Q--){
		ll opt=read(),l=read(),r=read();
		if(opt==1){
			change(l,a[l],-1);
			ll A=pre[l],B=nxt[l];
			nxt[A]=B;	pre[B]=A;
			pre[0]=nxt[0]=0;
			g[a[l]].erase(l);
			a[l]=r;	g[r].insert(l);
			set<ll>::iterator t=g[r].lower_bound(l);
			nxt[l]=pre[l]=0;
			++t;
			if (t!=g[r].end()){
				pre[*t]=l;	nxt[l]=*t;
			}--t;
			if (t!=g[r].begin()){	--t;	nxt[*t]=l;	pre[l]=*t;	}
			change(l,a[l],1);
		}
		else	writeln(query(l,r));
	}
}
/* 
?????????a[x],a[x+1],f[a[x],a[x+1]] 
f[x]
7 6
1 2 3 1 3 2 1
1 7 2
1 3 2
2 1 6

7 6
1 2 2 1 3 2 2
2 1 6
*/