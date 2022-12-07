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
const int N=400005;
struct node{
	int r1,c1,r2,c2,id,ans;
	bool operator <(const node &a)const{
		return r2<a.r2;
	}
}q[N];
bool cmp(node a,node b){
	return a.r2<b.r2;
}
bool cmpid(node a,node b){
	return a.id<b.id;
}
int n,Q,top,pos;
int a[N],lg[N],stk[N];
int st[20][N];

struct SEG{
	int t[N*4],nn;
	void init(int n){
		for (nn=1;nn<=n;nn<<=1);
		For(i,1,2*nn-1) t[i]=1<<30;
	}
	void change(int x,int v){
		x+=nn; t[x]=v;
		for (x>>=1;x;x>>=1) t[x]=min(t[x*2],t[x*2+1]); 
	}
	int query(int l,int r){
		if (l>r) return 1<<30;
		int ans=1<<30;
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=min(ans,t[l^1]);
			if (r&1)	ans=min(ans,t[r^1]); 
		}
		return ans;
	}
}SEG1,SEG2;
int qmin(int l,int r){
	if (l>r) swap(l,r);
	int k=lg[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int find_lower(int l,int r,int key){
	int ans=l-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (a[stk[mid]]<=key)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans+1;
}
void insert_ele(int at,int p){
	stk[at]=p;
	SEG1.change(at,-2*p+a[p]);
	SEG2.change(at,-2*p-a[p]);
}
void func(node &q,int key){
	int ans=abs(min(q.c1,key)-q.c2);
	//cout<<q.c1<<' '<<q.c2<<' '<<key<<endl;
	//cout<<q.id<<' '<<ans<<' '<<"F"<<endl;
	int p1=lower_bound(stk+1,stk+top+1,q.r1)-stk;
	int p2=find_lower(p1,top,q.c2);
	//cout<<q.c1<<' '<<q.c2<<' '<<q.r1<<' '<<q.r2<<' '<<key<<' '<<p2<<' '<<p1<<' '<<top<<endl;
	if (p2-1<=top&&stk[p2-1]>=q.r1) ans=min(ans,abs(a[stk[p2-1]]-q.c2)+1);
	if (p2-0<=top&&stk[p2-0]>=q.r1) ans=min(ans,abs(a[stk[p2-0]]-q.c2)+1);
	//cout<<q.id<<' '<<ans<<' '<<"F"<<endl;
	q.ans=min(q.ans,abs(q.r1-q.r2)+ans);
}
void update1(node &q){
	int key=qmin(q.r1,q.r2);
	func(q,key);
	int ed=lower_bound(stk+1,stk+top+1,q.r1+1)-stk-1;
	key=min(key,q.c1);
	int p1=find_lower(1,ed,key);
	int p2=find_lower(1,ed,q.c2);
	if (key>=q.c2){
		int val1=SEG1.query(p2,p1-1)+2*q.r1-q.c2;
		int val2=SEG2.query(1, p2-1)+2*q.r1+q.c2;
		//cout<<"DEBUG1 "<<key<<' '<<ed<<' '<<top<<' '<<p1<<' '<<p2<<endl;
		//cout<<"DEBUG2 "<<val1<<' '<<val2<<' '<<q.r1<<' '<<q.r2<<' '<<q.ans<<endl;
		q.ans=min(q.ans,abs(q.r1-q.r2)+min(val1,val2));
	}
	else{
		int val1=SEG1.query(p2,ed  )+2*q.r1-q.c2+1;
		int val2=SEG2.query(p1,p2-1)+2*q.r1+q.c2+1;
		//cout<<"DEBUG3 "<<key<<' '<<ed<<' '<<top<<' '<<p1<<' '<<p2<<endl;
		//cout<<"DEBUG4 "<<val1<<' '<<val2<<' '<<q.r1<<' '<<q.r2<<' '<<q.ans<<endl;
		q.ans=min(q.ans,abs(q.r1-q.r2)+min(val1,val2));
	}
}
void update2(node &q){
	int key=min(q.c1,qmin(q.r1,q.r2));
	q.ans=min(q.ans,abs(q.r1-q.r2)+abs(key-q.c2));
	int ed=lower_bound(stk+1,stk+top+1,q.r2+1)-stk-1;
	int p1=find_lower(1,ed,key);
	int p2=find_lower(1,ed,q.c2);
	if (key>=q.c2){
		int val1=SEG1.query(p2,p1-1)+2*q.r2-q.c2;
		int val2=SEG2.query(1, p2-1)+2*q.r2+q.c2;
		//cout<<"DEBUG1 "<<key<<' '<<ed<<' '<<top<<' '<<p1<<' '<<p2<<endl;
		//cout<<"DEBUG2 "<<val1<<' '<<val2<<' '<<q.r1<<' '<<q.r2<<' '<<q.ans<<endl;
		q.ans=min(q.ans,abs(q.r1-q.r2)+min(val1,val2));
	}
	else{
		int val1=SEG1.query(p2,ed  )+2*q.r2-q.c2+1;
		int val2=SEG2.query(p1,p2-1)+2*q.r2+q.c2+1;
		//cout<<"DEBUG3 "<<key<<' '<<ed<<' '<<top<<' '<<p1<<' '<<p2<<endl;
		//cout<<"DEBUG4 "<<val1<<' '<<val2<<' '<<q.r1<<' '<<q.r2<<' '<<q.ans<<endl;
		q.ans=min(q.ans,abs(q.r1-q.r2)+min(val1,val2));
	}
}
void solve(){
	memcpy(st[0],a,sizeof(st[0]));
	For(i,1,18) For(j,1,n-(1<<i)+1)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	For(i,1,Q){
		int key=qmin(q[i].r1,q[i].r2);
		q[i].ans=min(q[i].ans,abs(q[i].r1-q[i].r2)+abs(min(key,q[i].c1)-q[i].c2));
	}
	sort(q+1,q+Q+1,cmp);
	top=0,pos=1;
	SEG1.init(n);
	SEG2.init(n);
	For(i,1,n){
		for (;top&&a[stk[top]]>=a[i];--top);
		insert_ele(++top,i);
		//cout<<i<<' '<<top<<endl;
		for (;pos<=Q&&q[pos].r2==i;++pos)
			if (q[pos].r1<=q[pos].r2) update1(q[pos]);
			else update2(q[pos]);
	}
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) lg[i]=lg[i/2]+1;
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d%d",&q[i].r1,&q[i].c1);
		scanf("%d%d",&q[i].r2,&q[i].c2);
		q[i].id=i;
		q[i].ans=abs(q[i].r1-q[i].r2)+q[i].c2+1;
	}
	solve();
	reverse(a+1,a+n+1);
	For(i,1,Q){
		q[i].r1=n-q[i].r1+1;
		q[i].r2=n-q[i].r2+1;
	}
	solve();
	sort(q+1,q+Q+1,cmpid);
	For(i,1,Q) printf("%d\n",q[i].ans);
}