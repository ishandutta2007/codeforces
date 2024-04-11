#include<bits/stdc++.h>
#define N 200005

int n,a[N];

int val[N],tot;

int b[N],c[N][2];

struct node{
	int s[2],t[2];
	node(){
		s[0]=s[1]=0,t[0]=t[1]=-1;
	}
}t[N<<2];
node operator + (node x,node y){
	if(x.t[0]==-1||y.t[0]==-1)
		return x.t[0]==-1?y:x;
	for(int o=0;o<2;o++)
		y.s[o]+=x.s[y.t[o]],y.t[o]=x.t[y.t[o]];
	return y;
}
inline void ins(int p,int L,int R,int x){
	if(L==R)
		return t[p].s[0]=b[x]>0,t[p].t[0]=b[x]==1,t[p].s[1]=t[p].t[1]=0,void();
	int mid=(L+R)>>1;
	x<=mid?ins(p<<1,L,mid,x):ins(p<<1|1,mid+1,R,x);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline node sum(int p,int L,int R,int l,int r){
	if(l>r||L>r||R<l)
		return node();
	if(l<=L&&R<=r)
		return t[p];
	int mid=(L+R)>>1;
	return sum(p<<1,L,mid,l,r)+sum(p<<1|1,mid+1,R,l,r);
}

inline void upd(int i){
	if(c[i+1][0]&&c[i+1][1])
		b[i]=2;
	else if((c[i][0]&&c[i+1][1])||(c[i][1]&&c[i+1][0]))
		b[i]=1;
	else
		b[i]=0;
	ins(1,0,tot,i);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),val[++tot]=a[i];
	val[++tot]=0;
	std::sort(val+1,val+tot+1),tot=std::unique(val+1,val+tot+1)-val-1;
	for(int i=1;i<=n;i++)
		a[i]=std::lower_bound(val+1,val+tot+1,a[i])-val,c[a[i]][0]++;
	c[1][0]++,c[1][1]++;
	b[0]=2;
	for(int i=0;i<tot;i++)
		upd(i);
	long long res=0;
	for(int i=1;i<=n;i++){
		res+=sum(1,0,tot,0,a[i]-2).s[0];
		c[a[i]][0]--,c[a[i]][1]++;
		upd(a[i]-1),upd(a[i]);
	}
	printf("%lld\n",res);
}