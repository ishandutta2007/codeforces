#include<ctime>
#include<algorithm>
#include<cstdio>
#include<vector>
#define ll long long
#define maxn 2000010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
struct data{	ll mn,mx,sum;	}tr[maxn];
struct dt{	ll x,y,z;	}p[maxn];
ll n,A,B,C,my[maxn],mz[maxn],tag[maxn],answ;
vector<ll>g[maxn/4];
void updata(ll p){
	tr[p].mn=min(tr[p<<1].mn,tr[p<<1|1].mn);
	tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void pushdown(ll p,ll sz1,ll sz2){
	if (tag[p]){
		tag[p<<1]=tag[p<<1|1]=tr[p<<1].mn=tr[p<<1].mx=tr[p<<1|1].mn=tr[p<<1|1].mx=tag[p];
		tr[p<<1].sum=sz1*tag[p];
		tr[p<<1|1].sum=sz2*tag[p];
		tag[p]=0;
	}
}
void change(ll p,ll l,ll r,ll s,ll t,ll v){
	ll mid=(l+r)>>1;
//	printf("%lld %lld %lld %lld %lld %lld\n",p,l,r,s,t,v);
	if (l!=r)	pushdown(p,mid-l+1,r-mid);
	if (l==s&&r==t){
		if (l==r){	tr[p].mx=tr[p].mn=tr[p].sum=tag[p]=max(tr[p].mn,v);	return;	}
		if (tr[p<<1].mx<=v){	tag[p<<1]=v=tr[p<<1].mx=tr[p<<1].mn=v;	tr[p<<1].sum=v*(mid-l+1);	}
		else	if (tr[p<<1].mn<v)	change(p<<1,l,mid,s,mid,v);
		if (tr[p<<1|1].mx<=v){	tag[p<<1|1]=tr[p<<1|1].mx=tr[p<<1|1].mn=v;	tr[p<<1|1].sum=v*(r-mid);}
		else	if (tr[p<<1|1].mn<v)	change(p<<1|1,mid+1,r,mid+1,t,v);
		updata(p);	return;
	}
	if (t<=mid)	change(p<<1,l,mid,s,t,v);
	else if (s>mid)	change(p<<1|1,mid+1,r,s,t,v);
	else change(p<<1,l,mid,s,mid,v),change(p<<1|1,mid+1,r,mid+1,t,v);
	updata(p);
}
ll query(ll p,ll l,ll r,ll s,ll t,ll v){
	if (s>t)	return 0;
	ll mid=(l+r)>>1;
	if (l!=r)	pushdown(p,mid-l+1,r-mid);
	if (l==s&&r==t){
		if (l==r)	return C-max(tr[p].sum,v);
		ll ans=0;
		if (tr[p<<1].mx<=v)	ans=(C-v)*(mid-l+1);
		else	if ((tr[p<<1].mn<=v)&&(tr[p<<1].mx>v))	ans=query(p<<1,l,mid,s,mid,v);
		else	ans=C*(mid-l+1)-tr[p<<1].sum;
//		printf("%lld-\n",ans);
 		if (tr[p<<1|1].mx<=v)ans+=(C-v)*(r-mid);
		else	if ((tr[p<<1|1].mn<=v)&&(tr[p<<1|1].mx>v))	ans+=query(p<<1|1,mid+1,r,mid+1,t,v);
		else	ans+=C*(r-mid)-tr[p<<1|1].sum;
//		printf("%lld %lld %lld %lld %lld %lld %lld\n",p,l,r,s,t,v,ans);
		return ans;
	}
	if (t<=mid)	return query(p<<1,l,mid,s,t,v);
	else if (s>mid)	return query(p<<1|1,mid+1,t,s,t,v);
	else	return query(p<<1,l,mid,s,mid,v)+query(p<<1|1,mid+1,r,mid+1,t,v);
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	A=read();	B=read();	C=read();
	For(i,1,n)	p[i].x=read(),p[i].y=read(),p[i].z=read(),g[p[i].x].push_back(i);
	FOr(i,A+1,1){
		my[i]=my[i+1];	mz[i]=mz[i+1];
		if (g[i].size())	For(j,0,g[i].size()-1)	my[i]=max(my[i],p[g[i][j]].y),mz[i]=max(mz[i],p[g[i][j]].z);
	}
	For(i,1,A){
		ll My=my[i],Mz=mz[i];
//		printf("%lld %lld\n",My,Mz);
		if (g[i-1].size())	For(j,0,g[i-1].size()-1)	change(1,1,B,1,p[g[i-1][j]].y,p[g[i-1][j]].z);
		answ+=query(1,1,B,My+1,B,Mz);
//		writeln(answ);
	}writeln(answ);
}