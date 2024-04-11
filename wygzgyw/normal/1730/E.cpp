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
const int maxn=(1e6)+10;
int T,n,a[maxn];
int nxt[maxn];
int lst[maxn];
int v1[maxn],v2[maxn],L[maxn],R[maxn];
int tot,st[maxn];
ll ans;
int rub[15000000],buc[maxn];
int *d[maxn];
int hd[maxn];
int stt[maxn][20];
int lg[maxn];
int query(int l,int r) {
	int j=lg[r-l+1];
	return min(stt[l][j],stt[r-(1<<j)+1][j]);
}
int Get1(int i,int y) {
	int l=1,r=i,mid,res;
	while (l<=r) {
		mid=(l+r)>>1;
		if (query(mid,i)>=y) res=mid,r=mid-1; else l=mid+1;
	} return res;
}
int Get2(int i,int y) {
	int l=i,r=n,mid,res;
	while (l<=r) {
		mid=(l+r)>>1;
		if (query(i,mid)>=y) res=mid,l=mid+1; else r=mid-1;
	} return res;
}
int pre[maxn],suf[maxn];
int solve(int x,int y,int l,int r) {
	return max(0,min(y,r)-max(x,l)+1);
}
int main() {
//	freopen("1.txt","r",stdin);
	for (int i=1;i<maxn;i++) for (int j=i;j<maxn;j+=i) buc[j]++;
	int *now=rub;
	for (int i=1;i<maxn;i++) d[i]=now,now+=buc[i],buc[i]=0;
	for (int i=1;i<maxn;i++) for (int j=i;j<maxn;j+=i) d[j][buc[j]++]=i;
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		ans=0;
		
		memset(lst,0,sizeof(lst));
		for (int i=n;i>=1;i--) nxt[i]=lst[a[i]],lst[a[i]]=i;
		
		for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
		for (int i=1;i<=n;i++) stt[i][0]=a[i];
		for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++) stt[j][i]=min(stt[j][i-1],stt[j+(1<<(i-1))][i-1]);
		
		tot=0;
		for (int i=1;i<=n;i++) {
			while (tot&&a[st[tot]]<a[i]) tot--;
			L[i]=st[tot],st[++tot]=i;
		}
		tot=0;
		for (int i=n;i>=1;i--) {
			while (tot&&a[st[tot]]<=a[i]) tot--;
			R[i]=(!tot?n+1:st[tot]),st[++tot]=i;
		}
		
		tot=0;
		for (int i=1;i<=n;i++) {
			while (tot&&a[st[tot]]>=a[i]) tot--;
			v1[i]=st[tot],st[++tot]=i;
		}
		tot=0;
		for (int i=n;i>=1;i--) {
			while (tot&&a[st[tot]]>=a[i]) tot--;
			v2[i]=(!tot?n+1:st[tot]),st[++tot]=i;
		}
		memset(hd,0,sizeof(hd));
		for (int i=1;i<=n;i++) if (!hd[a[i]]) hd[a[i]]=i;
		memset(lst,0,sizeof(lst));
		for (int i=1;i<=n;i++) pre[i]=(a[i]==a[i-1]?pre[i-1]:i);
		for (int i=n;i>=1;i--) suf[i]=(a[i]==a[i+1]&&i<n?suf[i+1]:i);
		for (int i=1;i<=n;i++) L[i]++,R[i]--,v1[i]++,v2[i]--;
		for (int i=1;i<=n;i++) {
			lst[a[i]]=i; int x=a[i];
			for (int j=0;j<buc[x];j++) {
				int y=d[x][j],a=lst[y];
				if (x==y) {
					ans+=(ll)(i-max(L[i],pre[i])+1)*(min(R[i],suf[i])-i+1);
					continue;
				}
				int b=(!a?hd[y]:nxt[a]);
				if (a<L[i]) a=0;
				if (b>R[i]) b=0;
				if (a) ans+=(ll)solve(L[i],i,v1[a],a)*solve(i,R[i],a,v2[a]);
				if (b) ans+=(ll)solve(L[i],i,v1[b],b)*solve(i,R[i],b,v2[b]);
				if (a&&b) ans-=(ll)solve(L[i],i,max(v1[a],v1[b]),min(a,b))*solve(i,R[i],max(a,b),min(v2[a],v2[b]));
			}
			//printf("%d %lld %d %d\n",i,ans,L[i],R[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}