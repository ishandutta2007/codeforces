#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,m,X,q[N],l[N],r[N];
int a[N],na[N],b[N],nb[N];

struct ZKW{
	int nn,t[N*4];
	void init(int *a,int n){
		for (nn=1;nn<=n;nn<<=1);
		for (int i=1;i<=n;i++) t[i+nn]=a[i];
		for (int i=nn-1;i>=1;i--)
			t[i]=max(t[i*2],t[i*2+1]);
	}
	int ask(int l,int r){
		int ans=0;
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=max(ans,t[l^1]);
			if (r&1)	ans=max(ans,t[r^1]);
		}
		return ans;
	}
}T1;
void init(int *a,int *na,int n){
	int t=q[1]=1;
	for (int i=2;i<=n;i++){
		for (;t&&a[i]<=a[q[t]];--t) r[q[t]]=i;
		l[i]=q[t]; q[++t]=i;
	}
	for (;t;--t) r[q[t]]=n+1;
	T1.init(a,n);
	for (int i=1;i<=n;i++){
		int v1,v2;
		if (l[i]==1-1) v1=N;
		else v1=(l[i]==i-1?a[i]:T1.ask(l[i]+1,i-1));
		if (r[i]==n+1) v2=N;
		else v2=(r[i]==i+1?a[i]:T1.ask(i+1,r[i]-1));
		na[i]=min(v1,v2);
	}
}
pair<int,int> qa[N],qb[N];
int t[N*2];
void change(int x){
	for (;x<N*2;x+=x&(-x)) t[x]++;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
int main(){
	scanf("%d%d%d",&n,&m,&X); ++X;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	init(a,na,n);
	init(b,nb,m);
	for (int i=1;i<=n;i++)
		qa[i]=pair<int,int>(na[i]-a[i],a[i]);
	for (int i=1;i<=m;i++)
		qb[i]=pair<int,int>(nb[i]-b[i],b[i]);
	sort(qa+1,qa+n+1);
	sort(qb+1,qb+m+1);
	
	long long ans=0;
	int pa=n,pb=m;
	for (;pa>=1||pb>=1;)
		if (pb<1||(pa>=1&&qa[pa].first>qb[pb].first)){
			int r=X-qa[pa].second-1;
			int l=r+1-qa[pa].first;
			if (r>=1) ans+=ask(r);
			if (l>=1) ans-=ask(l-1);
			pa--;
		}
		else{
			change(qb[pb].second);
			pb--;
		}
	memset(t,0,sizeof(t));
	pa=n; pb=m;
	for (;pa>=1||pb>=1;)
		if (pa<1||(pb>=1&&qb[pb].first>=qa[pa].first)){
			int r=X-qb[pb].second-1;
			int l=r+1-qb[pb].first;
			if (r>=1) ans+=ask(r);
			if (l>=1) ans-=ask(l-1);
			pb--;
		}
		else{
			change(qa[pa].second);
			pa--;
		}
	printf("%lld\n",ans);
}