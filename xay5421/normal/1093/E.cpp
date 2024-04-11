#include <cstdio>
#include <algorithm>
const int MAXN=200005;

int n,m,tot,a[MAXN],b[MAXN],pa[MAXN],pb[MAXN],tr[MAXN],ans[MAXN*10];
bool tag[MAXN*10],used[MAXN*10];

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=x*10+(ch&15);
	if (fl) x=-x;
}

struct ASK{
	int opt,x,y,id;
} q[MAXN*10],qq[MAXN*10];

void upd(int i,int x){for (;i<=n;i+=i&-i) tr[i]+=x;}
int qry(int i){int res=0;for (;i;i&=i-1) res+=tr[i];return res;}

void cdq(int l,int r){
	if (l>=r) return;
	int mid=l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	int i=l,j=mid+1;
	for (int k=l;k<=r;++k){
		if (i<=mid&&(j>r||q[i].x<=q[j].x)){
			if (q[i].opt==2) upd(q[i].y,1);
			if (q[i].opt==3) upd(q[i].y,-1);
			qq[k]=q[i++],used[k]=1;
		} else{
			if (q[j].opt==1) ans[q[j].id]+=qry(q[j].y);
			qq[k]=q[j++];
		}
	}
	for (int k=l;k<=r;++k){
		q[k]=qq[k];
		if (used[k]==1){
			if (q[k].opt==2) upd(q[k].y,-1); else
			if (q[k].opt==3) upd(q[k].y,1);
			used[k]=0;
		}
	}
}

int main(){
	read(n),read(m);
	for (int i=1;i<=n;++i) read(a[i]),pa[a[i]]=i;
	for (int i=1;i<=n;++i) read(b[i]),pb[b[i]]=i;
	for (int i=1;i<=n;++i) ++tot,q[tot]=(ASK){2,pa[i],pb[i]};
	for (int i=1;i<=m;++i){
		++tot,read(q[tot].opt);
		if (q[tot].opt==1){
			int l1,r1,l2,r2; read(l1),read(r1),read(l2),read(r2); tag[tot--]=1;
			++tot,q[tot]=(ASK){1,r1,r2,tot};
			++tot,q[tot]=(ASK){1,l1-1,r2,tot};
			++tot,q[tot]=(ASK){1,r1,l2-1,tot};
			++tot,q[tot]=(ASK){1,l1-1,l2-1,tot};
		} else{
			int x,y; read(x),read(y); --tot;
			++tot,q[tot]=(ASK){3,pa[b[x]],x,0};
			++tot,q[tot]=(ASK){3,pa[b[y]],y,0};
			++tot,q[tot]=(ASK){2,pa[b[x]],y,0};
			++tot,q[tot]=(ASK){2,pa[b[y]],x,0};
			std::swap(b[x],b[y]),std::swap(pb[b[x]],pb[b[y]]);
		}
	}
	cdq(1,tot);
	for (int i=1;i<=tot;++i)
		if (tag[i]==1) printf("%d\n",ans[i]-ans[i+1]-ans[i+2]+ans[i+3]);
	return 0;
}