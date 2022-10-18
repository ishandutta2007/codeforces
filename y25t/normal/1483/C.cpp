#include<cstdio>
#include<algorithm>
#include<stack>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 300005

int n,h[N],b[N];

int pl[N],pr[N];
std::stack<int> st;

ll t[N<<2],val[N<<2];
inline void build(int p,int L,int R){
	t[p]=val[p]=-inf;
	if(L==R)
		return;
	int mid=(L+R)>>1;
	build(p<<1,L,mid);
	build(p<<1|1,mid+1,R);
}
inline void pshd(int p){
	t[p<<1]=std::max(t[p<<1],t[p]);
	val[p<<1]=std::max(val[p<<1],t[p]);
	t[p<<1|1]=std::max(t[p<<1|1],t[p]);
	val[p<<1|1]=std::max(val[p<<1|1],t[p]);
	t[p]=-inf;
}
inline void chg(int p,int L,int R,int l,int r,ll d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		t[p]=std::max(t[p],d);
		val[p]=std::max(val[p],d);
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	chg(p<<1,L,mid,l,r,d);
	chg(p<<1|1,mid+1,R,l,r,d);
	val[p]=std::max(val[p<<1],val[p<<1|1]);
}
inline ll mx(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return -inf;
	if(l<=L&&R<=r)
		return val[p];
	pshd(p);
	int mid=(L+R)>>1;
	ll res=-inf;
	res=std::max(res,mx(p<<1,L,mid,l,r));
	res=std::max(res,mx(p<<1|1,mid+1,R,l,r));
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		while(st.size()&&h[st.top()]>h[i]){
			pr[st.top()]=i-1;
			st.pop();
		}
		st.push(i);
	}
	while(st.size()){
		pr[st.top()]=n;
		st.pop();
	}
	for(int i=n;i;i--){
		while(st.size()&&h[st.top()]>h[i]){
			pl[st.top()]=i+1;
			st.pop();
		}
		st.push(i);
	}
	while(st.size()){
		pl[st.top()]=1;
		st.pop();
	}
	build(1,0,n);
	chg(1,0,n,0,0,0);
	for(int i=1;i<=n;i++){
		chg(1,0,n,i,pr[i],mx(1,0,n,pl[i]-1,i-1)+b[i]);
	}
	printf("%lld\n",mx(1,0,n,n,n));
}