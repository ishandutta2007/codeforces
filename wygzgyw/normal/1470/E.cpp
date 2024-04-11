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
typedef long long ll;
const int maxn=(4e5)+10;
int T,n,C,p[maxn];
struct node {
	int l,r; ll w;
} q[5][maxn];
ll calc(ll n,int c) {
	if (n<=0) return 1;
	ll res=0,t=1;
	for (int i=0;i<=c;i++) {
		if (i) t=t*(n-i+1)/i;
		res+=t;
	}
	return res;
}
int c;
node Gen(int l,int r) {
	return (node){l,r,calc(n-r-1,c-(r-l))};
}
ll sum[5][maxn];
int hd[5],tl[5],L[5][maxn],R[5][maxn],Q;
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n),read(C),read(Q);
		for (int i=1;i<=n;i++) read(p[i]);
		for (c=1;c<=C;c++) {
			hd[c]=maxn/2,tl[c]=hd[c]-1;
			q[c][++tl[c]]=(node){n,n,1};
			for (int i=n;i>=1;i--) {
				int bd=min(n,i+c);
				vector<pair<int,int> > vec;
				for (int j=i+1;j<=bd;j++) if (p[j]<p[i]) vec.push_back(MP(p[j],j));
				sort(vec.begin(),vec.end());
				for (int j=(int)vec.size()-1;j>=0;j--) {
					hd[c]--,q[c][hd[c]]=Gen(i,vec[j].second);
				}
				vec.clear();
				for (int j=i+1;j<=bd;j++) if (p[j]>p[i]) vec.push_back(MP(p[j],j));
				sort(vec.begin(),vec.end());
				for (int j=0;j<vec.size();j++) {
					tl[c]++,q[c][tl[c]]=Gen(i,vec[j].second);
				}
				L[c][i]=hd[c],R[c][i]=tl[c];
			}
			sum[c][hd[c]-1]=0;
			for (int i=hd[c];i<=tl[c];i++) sum[c][i]=sum[c][i-1]+q[c][i].w;
		}
		ll tmp=calc(n-1,C);
		while (Q--) {
			int x; ll y; read(x),read(y);
			if (y>tmp) { puts("-1"); continue; }
			int rst=C; vector<pair<int,int> > vec;
			int now=1;
			while (rst>0&&now<=n) {
				int pos=lower_bound(sum[rst]+L[rst][now],sum[rst]+R[rst][now]+1,sum[rst][L[rst][now]-1]+y)-sum[rst];
				//if (now==4) { for (int i=L[rst][now];i<=R[rst][now];i++) printf("(%d,%d,%lld)\n",q[rst][i].l,q[rst][i].r,q[rst][i].w); puts(""); }
				//printf("?? %d now=%d %lld %lld\n",rst,now,y,sum[rst][R[rst][now]]-sum[rst][L[rst][now]-1]);
				assert(pos<=R[rst][now]);
				int l=q[rst][pos].l,r=q[rst][pos].r;
				vec.push_back(MP(l,r));
				y-=sum[rst][pos-1]-sum[rst][L[rst][now]-1];
				//printf("%d %d %lld\n",pos,L[rst][now],y);
				now=r+1; rst-=r-l;
			}
			int ans=p[x];
			for (pair<int,int> &A : vec) if (A.first<=x&&x<=A.second) { ans=p[A.first+A.second-x]; break; }
			printf("%d\n",ans);
		}
	}
	return 0;
}