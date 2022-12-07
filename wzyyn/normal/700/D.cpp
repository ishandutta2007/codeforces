#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
const int B=500;
struct node{
	int l,r,id;
	bool operator <(const node &a)const{
		return l/B==a.l/B?r<a.r:l<a.l;
	}
}q[N];
int n,Q,a[N],id[N];
int c1[N],c2[N],S[N];
int C1[N],q1[N],q2[N],ans[N];
int h1,t1,h2,t2;
void add(int x,int v){
	if (id[x]) c2[id[x]]+=v;
	else --c1[S[x]],S[x]+=v,++c1[S[x]];
}
int pop(){
	if (h1==t1) return q2[++h2];
	if (h2==t2) return q1[++h1];
	return q1[h1+1]<q2[h2+1]?q1[++h1]:q2[++h2];
}
int count(){
	h1=t1=h2=t2=0;
	For(i,1,B) C1[i]=c1[i];
	For(i,1,*id)
		if (c2[i]<=B) ++C1[c2[i]];
		else q2[++t2]=c2[i];
	sort(q2+1,q2+t2+1);
	int las=0,ans=0;
	For(i,1,B) if (C1[i]){
		if (las){
			ans+=las+i;
			if (i+las<B) ++C1[i+las];
			else q1[++t1]=i+las;
			--C1[i],las=0;
		}
		ans+=C1[i]/2*2*i;
		if (i*2<=B) C1[i*2]+=C1[i]/2;
		else For(j,1,C1[i]/2) q1[++t1]=i*2;
		if (C1[i]&1) las=i;
	}
	if (las){
		Rep(i,t1,h1+1) q1[i+1]=q1[i];
		q1[h1+1]=las; ++t1;
	}
	//cout<<las<<' '<<t1-h1<<' '<<t2-h2<<' '<<ans<<' '<<q1[1]<<' '<<q2[1]<<endl;
	for (;t1-h1+t2-h2>1;){
		int v1=pop(),v2=pop();
		ans+=v1+v2; q1[++t1]=v1+v2;
	}
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) ++S[a[i]];
	For(i,1,n) if (S[a[i]]>B&&!id[a[i]]) id[a[i]]=++*id;
	memset(S,0,sizeof(S));
	scanf("%d",&Q);
	For(i,1,Q) scanf("%d%d",&q[i].l,&q[i].r);
	For(i,1,Q) q[i].id=i;
	sort(q+1,q+Q+1);
	int l=1,r=0;
	For(i,1,Q){
		for (;r<q[i].r;add(a[++r],1));
		for (;l>q[i].l;add(a[--l],1));
		for (;r>q[i].r;add(a[r--],-1));
		for (;l<q[i].l;add(a[l++],-1));
		ans[q[i].id]=count();
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}