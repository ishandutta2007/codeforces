#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=200005;
int n,q,pos[N];char s[N];
bool cmp(const int x,const int y){return x<y;}
struct node{
	int dt,mn,mx,lv,vr,lvr;
	node change(int d)const{
		return(node){dt+d,mn+d,mx+d,lv-d,vr-d,lvr};
	}
	node operator+(const node&c)const{
		node b=c.change(dt),res;
		res=(node){b.dt,std::min(mn,b.mn),std::max(mx,b.mx),std::max({lv,b.lv,mx-b.mn*2}),std::max({vr,b.vr,-mn*2+b.mx}),std::max({lvr,b.lvr,lv+b.mx,mx+b.vr})};
		return res;
	}
}t[N<<2];
const node nul=(node){0,0,0,0,0,0},le=(node){1,0,1,0,1,1},ri=(node){-1,-1,0,2,1,1};
void bud(int u,int l,int r){
	if(l==r){pos[l]=u;t[u]=(s[l]=='('?le:ri);return;}int mid=l+r>>1;
	bud(u<<1,l,mid),bud(u<<1|1,mid+1,r);
	t[u]=t[u<<1]+t[u<<1|1];
}
void mdf(int u,int ch){
	u=pos[u],t[u]=(ch=='('?le:ri),u>>=1;
	while(u){
		t[u]=t[u<<1]+t[u<<1|1];
		u>>=1;
	}
}
int main(){
	scanf("%d%d%s",&n,&q,s+1);n=n-1<<1;
	bud(1,1,n);printf("%d\n",t[1].lvr);
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		mdf(x,s[y]),mdf(y,s[x]);
		std::swap(s[x],s[y]);
		printf("%d\n",t[1].lvr); 
	}
	return 0;
}