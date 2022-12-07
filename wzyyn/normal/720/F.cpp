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
const ll inf=1ll<<50;
const int N=100005;
int n,S[N],matl[N],matr[N];
int id[N],rk[N],pos[N],rt[N];
ll k,a[N],b[N],val[N];
ll diff,lim;
priority_queue<pll> Q;
struct TREE_S{
	ll t[N];
	void init(){
		memset(t,0,sizeof(t)); 
	}
	void change(int x,ll v){
		for (;x<=n+1;x+=x&(-x)) t[x]+=v; 
	}
	ll ask(int x){
		ll s=0;
		for (;x;x-=x&(-x)) s+=t[x];
		return s;
	}
}T1,T2;
struct TREE_MN{
	ll t[N];
	void init(){
		memset(t,1,sizeof(t));
	}
	void change(int x,ll v){
		for (;x<=n+1;x+=x&(-x)) t[x]=min(t[x],v); 
	}
	ll ask(int x){
		ll s=1ll<<60;
		for (;x;x-=x&(-x)) s=min(s,t[x]);
		return s;
	}
}T3;
ll count(ll x){
	ll sum=0;
	T1.init();
	For(i,0,n){
		int p1=lower_bound(b+1,b+n+2,a[i])-b;
		int p2=upper_bound(b+1,b+n+2,a[i]-x)-b-1;
		sum+=T1.ask(p2);
		T1.change(p1,1);
	}
	return sum;
}

namespace SEG{
	const int M=4000005;
	int ls[M],rs[M],nd;
	void insert(int &nk,int k,int l,int r,int p){
		nk=++nd;
		ls[nk]=ls[k]; rs[nk]=rs[k];
		if (l==r) return;
		int mid=(l+r)/2;
		if (p<=mid) insert(ls[nk],ls[k],l,mid,p);
		else insert(rs[nk],rs[k],mid+1,r,p);
	}
	int ask(int k,int l,int r,int p){
		if (!k||p==-1) return -1;
		if (l==r) return l;
		int mid=(l+r)/2;
		if (p<=mid){
			int tmp=ask(ls[k],l,mid,p);
			if (tmp!=-1) return tmp;
		}
		return ask(rs[k],mid+1,r,p);
	}
}

void update_val(int x){
	int l=0,r=n,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (pll(a[id[mid]],id[mid])>=pll(val[x],pos[x]))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	//cout<<"pos "<<x<<' '<<ans<<' '<<id[ans]<<' '<<a[id[ans]]<<endl;
	ans=SEG::ask(rt[x],0,n,ans);
	if (ans==-1) val[x]=inf;
	else val[x]=a[id[ans]],pos[x]=id[ans];
}
bool cmp(int x,int y){
	return a[x]==a[y]?x<y:a[x]<a[y];
}
void init_segment(){
	For(i,1,n+1) b[i+1]=a[i];
	sort(b+1,b+n+2);
	lim=max(k-n,0ll);
	ll l=-inf,r=inf,ans=inf+1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (count(mid)<=lim)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	T3.init();
	T2.init();
	T1.init();
	For(i,0,n){
		int p1=lower_bound(b+1,b+n+2,a[i])-b;
		int p2=upper_bound(b+1,b+n+2,a[i]-ans)-b-1;
		int pos=min(1ll*i,T3.ask(p2));
		++S[pos+1]; --S[i+1];
		lim-=T2.ask(p2);
		diff+=a[i]*T2.ask(p2)-T1.ask(p2);
		T3.change(p1,i);
		T2.change(p1,1);
		T1.change(p1,a[i]);
	}
	static vector<int> vec[N];
	--ans;
	//cout<<lim<<endl;
	For(i,0,n){
		int p1=lower_bound(b+1,b+n+2,a[i])-b;
		int p2=lower_bound(b+1,b+n+2,a[i]-ans)-b;
		val[i]=a[i]-ans;
		//cout<<p1<<' '<<p2<<' '<<b[p2]<<' '<<a[i]-ans<<endl;
		if (b[p2]==a[i]-ans&&vec[p2].size()){
			int v=min((ll)vec[p2].size(),lim);
			//cout<<v<<' '<<lim<<endl;
			pos[i]=(v==vec[p2].size()?vec[p2].back()+1:vec[p2][v]);
			lim-=v; diff+=1ll*v*ans;
			if (v) ++S[vec[p2][0]+1],--S[i+1];//vec[i]
		}
		else pos[i]=0;
		vec[p1].PB(i);
		//cout<<i<<' '<<val[i]<<' '<<pos[i]<<endl;
	}
	For(i,1,n) S[i]+=S[i-1];
	For(i,0,n) id[i]=i;
	sort(id,id+n+1,cmp);
	For(i,0,n) rk[id[i]]=i;
	For(i,1,n) SEG::insert(rt[i],rt[i-1],0,n,rk[i-1]); 
	For(i,1,n){
		//cout<<"INI "<<i<<' '<<pos[i]<<' '<<val[i]<<endl;
		update_val(i);
		//cout<<"INI "<<i<<' '<<pos[i]<<' '<<val[i]<<endl;
		Q.push(pll(a[i]-val[i],i));
	}
	For(i,1,min(1ll*n,k)){
		int x=Q.top().se; Q.pop();
		assert(val[x]!=-inf);
		matl[i]=++pos[x]; matr[i]=x;
		update_val(x);
		Q.push(pll(a[x]-val[x],x));
		//cout<<"info "<<matl[i]<<' '<<matr[i]<<endl;
	}
	//cout<<diff<<' '<<ans<<' '<<lim<<endl;
	//For(i,1,n) cout<<S[i]<<' '; cout<<endl;
}

namespace SEG2{
	const int M=4000005;
	int ls[M],rs[M],nd;
	ll s1[M],s2[M];
	void insert(int &k,ll l,ll r,ll p,ll v){
		//if (l==0&&r==3*inf)
		//	cout<<"C "<<p<<' '<<v<<endl;
		if (!k) k=++nd;
		s1[k]+=p*v; s2[k]+=v;
		if (l==r) return;
		ll mid=(l+r)/2;
		if (p<=mid) insert(ls[k],l,mid,p,v);
		else insert(rs[k],mid+1,r,p,v);
	}
	ll ask(int k,ll l,ll r,int rk){
		if (rk>s2[k]) return s1[k];
		if (!k) return s1[k];
		if (l==r) return rk*l;
		ll mid=(l+r)/2;
		if (s2[rs[k]]>rk) return ask(rs[k],mid+1,r,rk);
		return s1[rs[k]]+ask(ls[k],l,mid,rk-s2[rs[k]]);
	}
}
struct node{
	ll sl,sr,s,mn;
	node operator +(const node &a)const{
		node b;
		b.s=s+a.s;//max(a.s,b.s);
		b.mn=min(min(mn,a.mn),sr+a.sl);
		b.sl=min(sl,s+a.sl);
		b.sr=min(a.sr,a.s+sr);
		return b;
	}
}t1[N],t2[N];
set<int> SS;
int L[N],R[N],rtt,rem;
void merge(int x,int y){
	//cout<<"merge "<<x<<' '<<y<<endl; 
	int l=L[x],r=R[y];
	++rem;
	SEG2::insert(rtt,0,3*inf,max(-t1[l].mn,-t2[l].mn),-1);
	SEG2::insert(rtt,0,3*inf,max(-t1[y].mn,-t2[y].mn),-1);
	t1[l]=t1[l]+t1[y];
	t2[l]=t2[l]+t2[y];
	R[l]=r; L[r]=l;
	SEG2::insert(rtt,0,3*inf,max(-t1[l].mn,-t2[l].mn),1);
}
void insert(int id){
	ll val=(id==0||id==n+1?-inf:a[id]-a[id-1]);
	L[id]=R[id]=id;
	t1[id]=(node){val,val,val,val};
	t2[id]=(node){-val,-val,-val,-val};
	SEG2::insert(rtt,0,3*inf,max(-val,val),1);
	if (id==0||id==n+1) return;
	rem-=2;
	if (R[id-1]!=-1) merge(id-1,id);
	if (L[id+1]!=-1) merge(id,id+1);
}
ll ask(int x){
	if (R[0]==n+1) return (x==0?0:-10*inf);
	if (x>rem+SEG2::s2[rtt]-1) return -10*inf;
	//cout<<x<<' '<<SEG2::ask(rtt,0,3*inf,x+1)<<endl;
	return a[n]+SEG2::ask(rtt,0,3*inf,x+1)-2*inf;
}
void solve(){
	rem=n-1;
	For(i,0,n+1) L[i]=R[i]=-1;
	insert(0); insert(n+1); 
	For(i,1,n) if (S[i]) insert(i);
	else SS.insert(i);
	ll maxv=-(1ll<<60),sum=0;
	For(i,0,min(1ll*n,k)){
		if (i){
			set<int>::iterator it;
			it=SS.lower_bound(matl[i]);
			for (;it!=SS.end()&&*it<=matr[i];SS.erase(it++))
				insert(*it);
			sum+=a[matr[i]]-a[matl[i]-1];
		}
		//cout<<ask(min(1ll*n,k)-i)<<' '<<sum<<' '<<rem<<endl;
		maxv=max(maxv,ask(min(1ll*n,k)-i)+sum);
	}
	printf("%lld\n",diff+maxv);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%lld",&n,&k);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) a[i]+=a[i-1];
	init_segment();
	solve();
}
/*
3-4
3-5
4-4
2-4
10-10
3-10
1-4

16+11+9+8+8=42
*/