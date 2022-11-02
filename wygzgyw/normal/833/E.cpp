// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(3e5)+10;
const int INF=(2e9)+5;
int n,C,l,r,c[maxn],now,q;
vector<pair<int,int> > ev,ev2;
int ans[maxn];
int MX[maxn];
pair<int,int> Q[maxn];
map<pair<int,int>,int> M;
int lsh[maxn*4],N,len[maxn],id[maxn],bk[maxn];
set<int> s; set<int>::iterator it;
bool cmp(int x,int y) { return c[x]<c[y]; }
void insert(int x) {
	//printf("insert %d\n",x);
	s.insert(x);
	
}
void del(int x) {
	//printf("del %d\n",x);
	s.erase(x);
}
int Get(int x) {
	int l=1,r=n,mid,res=0;
	while (l<=r) {
		mid=(l+r)>>1;
		if (c[id[mid]]+x<=C) res=mid,l=mid+1; else r=mid-1;
	}
	return res;
}
namespace Seg {
	int tr[maxn*4];
	void update(int x,int l,int r,int root,int delta) {
		if (l==r) { tr[root]=delta; return; }
		int mid=(l+r)>>1;
		if (x<=mid) update(x,l,mid,root<<1,delta); else update(x,mid+1,r,root<<1|1,delta);
		tr[root]=max(tr[root<<1],tr[root<<1|1]);
	}
	int query(int L,int R,int l,int r,int root) {
		if (L>R) return 0;
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1,res=0;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=max(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
};
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(C);
	for (int i=1;i<=n;i++) {
		read(l),read(r),read(c[i]);
		ev.push_back(MP(l,i));
		ev2.push_back(MP(r,i));
		id[i]=i;
		lsh[++N]=l,lsh[++N]=r;
		lsh[++N]=r-1;
		if (l-1>=0) lsh[++N]=l-1;
	}
	sort(id+1,id+n+1,cmp); for (int i=1;i<=n;i++) bk[id[i]]=i;
	lsh[++N]=0;
	lsh[++N]=INF;
	sort(lsh+1,lsh+N+1), N=unique(lsh+1,lsh+N+1)-lsh-1;
	lsh[N+1]=lsh[N];
	read(q);
	for (int i=1;i<=q;i++) read(Q[i].first),Q[i].second=i;
	sort(Q+1,Q+q+1);
	sort(ev.begin(),ev.end()); sort(ev2.begin(),ev2.end());
	int p1=-1,p2=0,pp1=-1,x,y,tmp;
	int mx=0;
	for (int I=1;I<=N;I++) {
		while (p1+1<(int)ev.size()&&ev[p1+1].first<=lsh[I]) {
			p1++;
			insert(ev[p1].second);
		}
		while (pp1+1<(int)ev2.size()&&ev2[pp1+1].first<=lsh[I]) {
			pp1++;
			del(ev2[pp1].second);
		}
		int sz=(int)s.size(); tmp=lsh[I+1]-lsh[I];
		if (sz==0) {
			now+=tmp;
		} else if (sz==1) {
			x=(*s.begin());
			len[x]+=tmp;
			int pos=Get(c[x]);
			if (c[x]<=C) {
				if (bk[x]>pos) mx=max(mx,len[x]+Seg::query(1,pos,1,n,1));
				else mx=max(mx,len[x]+max(Seg::query(1,bk[x]-1,1,n,1),Seg::query(bk[x]+1,pos,1,n,1)));
				mx=max(mx,len[x]+MX[x]);
				Seg::update(bk[x],1,n,1,len[x]);
			}
		} else if (sz==2) {
			x=(*s.begin());  it=s.end(); it--; y=(*it);
			M[MP(x,y)]+=tmp;
			if (c[x]+c[y]<=C) {
				//printf("xyr %d %d %d, %d %d\n",c[x],c[y],M[MP(x,y)],len[x],len[y]);
				mx=max(mx,len[x]+len[y]+M[MP(x,y)]);
				MX[x]=max(MX[x],len[y]+M[MP(x,y)]);
				MX[y]=max(MX[y],len[x]+M[MP(x,y)]);
			}
		}
		//printf("   %d %d now=%d %d\n",lsh[I],mx,now,sz);
		while (p2<q&&Q[p2+1].first<=mx+now) {
			p2++;
			//cerr<<Q[p2].first<<endl;
			ans[Q[p2].second]=lsh[I+1]-(mx+now-Q[p2].first);
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/