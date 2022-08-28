//CF 1004F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int K = 22;
int n,q,w,a[N];
struct node{
	int sl,pl[K],cl[K];
	int sr,pr[K],cr[K];
	LL ans;
	node(){
		sl=0,sr=0,ans=0;
		memset(pl,0,sizeof(pl));
		memset(cl,0,sizeof(cl));
		memset(pr,0,sizeof(pr));
		memset(cr,0,sizeof(cr));
	}
}T[N<<2];
void pushup(int k){
	int i,j,s,ls=k<<1,rs=k<<1|1,L=T[ls].pr[T[ls].sr+1],R=T[rs].pl[T[rs].sl+1];
	T[k].ans=T[ls].ans+T[rs].ans;
	j=0;
	for(i=T[ls].sr;i>=0;i--){
		while(j<=T[rs].sl&&(T[ls].cr[i]|T[rs].cl[j])<w){
			j++;
		}
		T[k].ans+=(LL)(T[ls].pr[i]-T[ls].pr[i+1])*(R-T[rs].pl[j]);
	}
	for(i=0;i<=T[ls].sl;i++)
		T[k].pl[i]=T[ls].pl[i],T[k].cl[i]=T[ls].cl[i];
	j=T[ls].sl;
	s=T[ls].cl[j];
	for(i=0;i<=T[rs].sl;i++)
		if((s|T[rs].cl[i])^s)
			s|=T[rs].cl[i],j++,T[k].pl[j]=T[rs].pl[i],T[k].cl[j]=s;
	T[k].sl=j;
	T[k].pl[j+1]=R;
	for(i=0;i<=T[rs].sr;i++)
		T[k].pr[i]=T[rs].pr[i],T[k].cr[i]=T[rs].cr[i];
	j=T[rs].sr;
	s=T[rs].cr[j];
	for(i=0;i<=T[ls].sr;i++)
		if((s|T[ls].cr[i])^s)
			s|=T[ls].cr[i],j++,T[k].pr[j]=T[ls].pr[i],T[k].cr[j]=s;
	T[k].sr=j;
	T[k].pr[j+1]=L;
}
LL ans;
int ss,pp[K],cc[K],t[K],h[K];
void getans(int k){
	int i,j,s,L=pp[ss+1],R=T[k].pl[T[k].sl+1];
	if(ss<0){
		ans=T[k].ans;
		ss=T[k].sr;
		for(i=0;i<=ss+1;i=i+1)
			pp[i]=T[k].pr[i],cc[i]=T[k].cr[i];
		return;
	}
	ans+=T[k].ans;
	j=0;
	for(i=ss;i>=0;i--){
		while(j<=T[k].sl&&(cc[i]|T[k].cl[j])<w){
			j++;
		}
		ans+=(LL)(pp[i]-pp[i+1])*(R-T[k].pl[j]);
	}
	for(i=0;i<=T[k].sr;i++)
		t[i]=T[k].pr[i],h[i]=T[k].cr[i];
	j=T[k].sr;
	s=T[k].cr[j];
	for(i=0;i<=ss;i++)
		if((s|cc[i])^s)
			s|=cc[i],j++,t[j]=pp[i],h[j]=s;
	ss=j;
	for(i=0;i<=j;i=i+1)
		pp[i]=t[i],cc[i]=h[i],t[i]=0,h[i]=0;
	pp[ss+1]=L;
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		T[k].sl=0,T[k].pl[0]=l,T[k].cl[0]=a[l],T[k].pl[1]=l+1;
		T[k].sr=0,T[k].pr[0]=r,T[k].cr[0]=a[r],T[k].pr[1]=r-1;
		T[k].ans=(a[l]>=w);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	pushup(k);
}
void modify(int x,int k=1,int l=1,int r=n){
	if(l==r){
		T[k].cl[0]=a[l];
		T[k].cr[0]=a[r];
		T[k].ans=(a[l]>=w);
		return;
	}
	int h=l+r>>1;
	if(x<=h)
		modify(x,k<<1,l,h);
	else
		modify(x,k<<1|1,h+1,r);
	pushup(k);
}
void query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		getans(k);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		query(L,R,k<<1,l,h);
	if(h<R)
		query(L,R,k<<1|1,h+1,r);
}
int main()
{
	int i,j,o;
	scanf("%d%d%d",&n,&q,&w);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	build();
	while(q--){
		scanf("%d%d%d",&o,&i,&j);
		if(o==1){
			a[i]=j;
			modify(i);
		}
		else{
			ans=0;
			ss=-1;
			memset(pp,0,sizeof(pp));
			memset(cc,0,sizeof(cc));
			query(i,j);
			cout<<ans<<endl;
		}
	}
	return 0;
}