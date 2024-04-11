// old
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>

const int MAXN=100005;
const int MAXB=350;

int n,m,b,a[MAXN],v[MAXN],f[MAXN],bel[MAXN],cnt[MAXN],tag[MAXN],bl[MAXN],br[MAXN],mx[MAXB],h[MAXB][MAXN];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	for (;!isdigit(ch=getchar());) fl^=ch=='-';
	x=(ch&15);
	for (;isdigit(ch=getchar());) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

inline int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}

void upd(int x){
	register int i;
	for (i=bl[x];i<=br[x];++i) a[i]=v[get(i)],h[x][a[i]]=0;
	for (i=bl[x];i<=br[x];++i) cnt[i]=1,f[i]=i;
	for (i=bl[x];i<=br[x];++i){
		if (h[x][a[i]]){
			cnt[h[x][a[i]]]+=cnt[i];
			f[i]=h[x][a[i]];
		} else{
			h[x][a[i]]=i;
			v[i]=a[i];
		}
	}
	for (;!h[x][mx[x]];--mx[x]);
}

void chg(int x,int l,int r,int val){
	register int i;
	for (i=bl[x];i<=br[x];++i) a[i]=v[get(i)],h[x][a[i]]=0;
	for (i=l;i<=r;++i) if (a[i]-tag[x]>val) a[i]-=val;
	for (i=bl[x];i<=br[x];++i) v[i]=a[i],f[i]=i;
	upd(x);
}

void mdf(int l,int r,int val){
	register int i,j;
	if (bel[l]==bel[r]){
		chg(bel[l],l,r,val);
		return;
	}
	chg(bel[l],l,br[bel[l]],val);
	chg(bel[r],bl[bel[r]],r,val);
	for (i=bel[l]+1;i<bel[r];++i){
		if (val*2<=mx[i]-tag[i]){
			for (j=tag[i]+1;j<=val+tag[i];++j)
				if (h[i][j]){
					if (!h[i][j+val]){
						h[i][j+val]=h[i][j];
						v[h[i][j]]=j+val;
						h[i][j]=0;
					} else{
						cnt[h[i][j+val]]+=cnt[h[i][j]];
						f[h[i][j]]=h[i][j+val];
						h[i][j]=0;
					}
				}
			tag[i]+=val;
		} else {
			for (j=val+tag[i]+1;j<=mx[i];++j)
				if (h[i][j]){
					if (!h[i][j-val]){
						h[i][j-val]=h[i][j];
						v[h[i][j]]=j-val;
						h[i][j]=0;
					} else {
						cnt[h[i][j-val]]+=cnt[h[i][j]];
						f[h[i][j]]=h[i][j-val];
						h[i][j]=0;
					}
				}
			for (;!h[i][mx[i]];--mx[i]);
		}
	}
}

int qry(int l,int r,int val){
	register int i; int res=0;
	if (bel[l]==bel[r]){
		for (i=l;i<=r;++i)
			if (v[get(i)]-tag[bel[l]]==val) ++res;
		return res;
	}
	for (i=l;i<=br[bel[l]];++i)
		if (v[get(i)]-tag[bel[l]]==val) ++res;
	for (i=bl[bel[r]];i<=r;++i)
		if (v[get(i)]-tag[bel[r]]==val) ++res;
	for (i=bel[l]+1;i<bel[r];++i)
		if (val+tag[i]<=100000) res+=cnt[h[i][val+tag[i]]];
	return res;
}
	
int main(){
	register int i; int opt,l,r,x;
	read(n),read(m); b=n/sqrt(m*2.0/3); if (b<1) b=1;
	for (i=1;i<=n;++i) bel[i]=(i-1)/b+1,f[i]=i;
	for (i=1;i<=bel[n];++i) bl[i]=(i-1)*b+1,br[i]=i*b;
	br[bel[n]]=n;
	for (i=1;i<=n;++i) read(a[i]),v[i]=a[i],mx[bel[i]]>=a[i]?0:mx[bel[i]]=a[i];
	for (i=1;i<=bel[n];++i) upd(i);
	for (i=1;i<=m;++i){
		read(opt),read(l),read(r),read(x);
		if (opt==1) mdf(l,r,x);
		else print(qry(l,r,x)),putchar('\n');
	}
	return 0;
}