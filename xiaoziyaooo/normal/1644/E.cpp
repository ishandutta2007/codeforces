#include<bits/stdc++.h>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=200005,maxp=maxn<<2,maxt=maxn<<4;
int n,m,T,tot,ls,ps;
long long ans;
int sumx[maxn],sumy[maxn],p[maxp],val[maxp],cnt[maxt],len[maxt];
map<int,int>mp;
string s;
struct line{
	int a,b,h,v;
}l[maxp];
inline int cmp(line a,line b){
	return a.h<b.h;
}
void build(int l,int r,int now){
	cnt[now]=len[now]=0;
	if(l==r)
		return ;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
}
void update(int l,int r,int now,int L,int R,int v){
	if(L>R)
		return ;
	if(L<=l&&r<=R){
		cnt[now]+=v;
		if(cnt[now]==0)
			len[now]=len[lc(now)]+len[rc(now)];
		else len[now]=val[r+1]-val[l];
		return ;
	}
	if(L<=mid)
		update(l,mid,lc(now),L,R,v);
	if(mid<R)
		update(mid+1,r,rc(now),L,R,v);
	if(cnt[now]==0)
		len[now]=len[lc(now)]+len[rc(now)];
}
void addrec(int a,int b,int c,int d){
	l[++ls].a=a,l[ls].b=c+1,l[ls].h=b,l[ls].v=1;
	l[++ls].a=a,l[ls].b=c+1,l[ls].h=d+1,l[ls].v=-1;
	p[++ps]=a,p[++ps]=c+1;
//	printf("addrec %d %d %d %d\n",a,b,c,d);
}
int main(){
	scanf("%d",&T);
	while(T--){
		ps=ls=tot=ans=0,mp.clear();
		scanf("%d",&n),cin>>s,m=s.size(),s=" "+s;
		for(int i=1;i<=m;i++){
			sumx[i]=sumx[i-1]+(s[i]=='D'),sumy[i]=sumy[i-1]+(s[i]=='R');
//			printf("[%d,%d]\n",sumx[i]+1,sumy[i]+1);
		}
		addrec(1,1,1,1);
		if(s[1]=='D')
			for(int i=1;i<=m;i++)
				addrec(sumx[i]+1,sumy[i]+1,sumx[i]+(n-sumx[m]),sumy[i]+1);
		if(s[1]=='R')
			for(int i=1;i<=m;i++)
				addrec(sumx[i]+1,sumy[i]+1,sumx[i]+1,sumy[i]+(n-sumy[m]));
		int okx=0,oky=0,pos=0;
		for(int i=1;i<=m;i++){
			okx|=(s[i]=='D'),oky|=(s[i]=='R');
			if(okx&&oky){
				pos=i;
				break;
			}
		}
		if(pos)
			for(int i=pos;i<=m;i++)
				addrec(sumx[i]+1,sumy[i]+1,sumx[i]+(n-sumx[m]),sumy[i]+(n-sumy[m]));
		sort(l+1,l+1+ls,cmp),sort(p+1,p+1+ps);
		for(int i=1;i<=ps;i++)
			if(i==1||p[i]!=p[i-1])
				tot++,mp[p[i]]=tot,val[tot]=p[i];
		for(int i=1;i<=ls;i++)
			l[i].a=mp[l[i].a],l[i].b=mp[l[i].b];
		build(1,tot,1);
		for(int i=1;i<=ls;i++){
			update(1,tot,1,l[i].a,l[i].b-1,l[i].v),ans+=1ll*len[1]*(l[i+1].h-l[i].h);
//			printf("l[i].a=%d l[i].b=%d l[i].v=%d l[i].h=%d len1=%d\n",l[i].a,l[i].b,l[i].v,l[i].h,len[1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}