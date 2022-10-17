#include<stdio.h>
const int maxn=200005,maxk=maxn*40;
int n,q,k,rt,cnt;
int lc[maxk],rc[maxk],lazy[maxk],Vand[maxk],Vor[maxk],res[maxk];
inline void swp(int &a,int &b){
	a+=b,b=a-b,a-=b;
}
inline void pushup(int now){
	Vand[now]=Vand[lc[now]]|Vand[rc[now]];
	Vor[now]=Vor[lc[now]]|Vor[rc[now]];
	res[now]=res[lc[now]]+res[rc[now]];
}
void insert(int dep,int &now,int val){
	if(now==0)
		now=++cnt;
	if(dep==0){
		Vand[now]=(k^val),Vor[now]=val,res[now]=1;
		return ;
	}
	if(((val>>(dep-1))&1)==0)
		insert(dep-1,lc[now],val);
	else insert(dep-1,rc[now],val);
	pushup(now);
}
void getxor(int dep,int now,int val){
	if(now==0)
		return ;
	if((val>>(dep-1))&1)
		swp(lc[now],rc[now]);
	int Va=Vand[now],Vo=Vor[now];
	Vand[now]=(Va&(k^val))|(Vo&val);
	Vor[now]=(Vo&(k^val))|(Va&val);
	lazy[now]^=val;
}
void pushdown(int dep,int now){
	if(lazy[now]==0)
		return ;
	getxor(dep-1,lc[now],lazy[now]),getxor(dep-1,rc[now],lazy[now]);
	lazy[now]=0;
}
void split(int dep,int &x,int &y,int l,int r,int L,int R){
	if(x==0||R<l||r<L){
		y=0;
		return ;
	}
	if(L<=l&&r<=R){
		y=x,x=0;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(dep,x),y=++cnt;
	split(dep-1,lc[x],lc[y],l,mid,L,R),split(dep-1,rc[x],rc[y],mid+1,r,L,R);
	pushup(x),pushup(y);
}
void merge(int dep,int &x,int &y){
	if(x==0){
		x=y;
		return ;
	}
	if(y==0||dep==0)
		return ;
	pushdown(dep,x),pushdown(dep,y);
	merge(dep-1,lc[x],lc[y]),merge(dep-1,rc[x],rc[y]);
	pushup(x);
}
void getor(int dep,int now,int val){
	if(now==0)
		return ;
	int add=val&Vand[now]; 
	if((add&Vor[now])==0){
		getxor(dep,now,add);
		return ;
	}
	pushdown(dep,now);
	if((val>>(dep-1))&1){
		getxor(dep-1,lc[now],1<<(dep-1));
		merge(dep-1,rc[now],lc[now]);
		lc[now]=0;
	}
	getor(dep-1,lc[now],val),getor(dep-1,rc[now],val);
	pushup(now);
}
int query(int dep,int now,int l,int r,int L,int R){
	if(now==0||R<l||r<L)
		return 0;
	if(L<=l&&r<=R)
		return res[now];
	int mid=(l+r)>>1;
	pushdown(dep,now);
	return query(dep-1,lc[now],l,mid,L,R)+query(dep-1,rc[now],mid+1,r,L,R);
}
void read(int &x){
	x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-48;
}
int main(){
	scanf("%d%d",&n,&q),k=(1<<20)-1;
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		insert(20,rt,x);
	}
	for(int i=1;i<=q;i++){
		int t,x,y,z,now;
		read(t);
		if(t==4){
			read(x),read(y);
			printf("%d\n",query(20,rt,0,k,x,y));
			continue;
		}
		read(x),read(y),read(z);
		split(20,rt,now,0,k,x,y);
		if(t==1)
			getxor(20,now,k),getor(20,now,z^k),getxor(20,now,k);
		if(t==2)
			getor(20,now,z);
		if(t==3)
			getxor(20,now,z);
		merge(20,rt,now);
	}
	return 0;
}//qwq