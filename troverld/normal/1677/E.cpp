/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a[200100],b[200100],stk[200100],tp,ch[200100][2],rt,P[200100],pre[200100],suf[200100],cnt;
vector<pair<int,int> >u[200100],v[200100];
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid ((l+r)>>1)
struct SegTree{int ch[2],tag;ll sum;}seg[25001000];
void modify(int&x,int y,int l,int r,int L,int R){
	// printf("modify:%d,%d,%d,%d,%d,%d\n",x,y,l,r,L,R);
	if(l>R||r<L)return;
	seg[x=++cnt]=seg[y];
	if(L<=l&&r<=R)return seg[x].tag++,seg[x].sum+=r-l+1,void();
	modify(lson,seg[y].ch[0],l,mid,L,R),modify(rson,seg[y].ch[1],mid+1,r,L,R),
	seg[x].sum=seg[lson].sum+seg[rson].sum+1ll*(r-l+1)*seg[x].tag;
}
ll query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].sum;
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R)+1ll*(min(R,r)-max(L,l)+1)*seg[x].tag;
}
void solve(int x,int l,int r){
	if(!x)return;
	solve(ch[x][0],l,x-1),solve(ch[x][1],x+1,r);
	// printf("%d[%d,%d]\n",x,l,r);
	if(x-l<r-x){
		// puts("L");
		for(int i=l;i<=x;i++)P[i]=r+1;
		for(int i=1;i*i<a[x];i++)if(!(a[x]%i)){
			int p=b[i],q=b[a[x]/i];
			if(p>q)swap(p,q);
			P[min(p,x)]=min(P[min(p,x)],max(q,x));
		}
		// for(int i=l;i<=x;i++)printf("[%d,%d]\n",P[i],r);
		for(int i=x-1;i>=l;i--)P[i]=min(P[i],P[i+1]);
		for(int i=l;i<=x;i++)u[i].emplace_back(P[i],r);
	}else{
		// puts("R");
		for(int i=x;i<=r;i++)P[i]=l-1;
		for(int i=1;i*i<a[x];i++)if(!(a[x]%i)){
			int p=b[i],q=b[a[x]/i];
			if(p>q)swap(p,q);
			P[max(q,x)]=max(P[max(q,x)],min(p,x));
		}
		for(int i=x+1;i<=r;i++)P[i]=max(P[i],P[i-1]);
		// for(int i=l;i<=x;i++)printf("[%d,%d]\n",l,P[i]);
		for(int i=x;i<=r;i++)v[i].emplace_back(l,P[i]);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=i;
	for(int i=1;i<=n;i++){
		while(tp&&a[stk[tp]]<a[i])ch[i][0]=stk[tp--];
		if(stk[tp])ch[stk[tp]][1]=i;stk[++tp]=i;
	}
	rt=stk[1];
	solve(rt,1,n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		for(auto x:u[i])if(x.first<=x.second)modify(pre[i],pre[i],1,n,x.first,x.second);
	}
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1];
		for(auto x:v[i])if(x.first<=x.second)modify(suf[i],suf[i],1,n,x.first,x.second);
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		printf("%lld\n",query(pre[r],1,n,l,r)-query(pre[l-1],1,n,l,r)+query(suf[l],1,n,l,r)-query(suf[r+1],1,n,l,r));
	}
	return 0;
}