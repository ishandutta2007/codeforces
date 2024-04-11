#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=300005,inf=1e9,M=1<<20|2;
vector<int> v[N<<1];
int n,tot,t1,t2,q1[N],q2[N],p[N];
int l[N<<1],r[N<<1],L[N],mx[N<<1],mn[N<<1],h[N<<1];
PI tr[M];
int lzy[M];
void cb(int x,int dq){//cout<<x<<" "<<dq<<endl;
	v[x].pb(dq); l[x]=min(l[x],l[dq]); r[x]=max(r[x],r[dq]); mx[x]=max(mx[x],mx[dq]); mn[x]=min(mn[x],mn[dq]);
}
bool check(int x){
	return mx[x]-mn[x]==r[x]-l[x];
}
void push_up(int nod){
	tr[nod]=min(tr[nod<<1],tr[nod<<1|1]); tr[nod].fi+=lzy[nod];
}
void cao(int nod,int de){
	lzy[nod]+=de; tr[nod].fi+=de;
}
void ins(int l,int r,int i,int j,int de,int nod){
	//if(l==1&&r==n)cout<<i<<" "<<j<<" "<<de<<endl;
	if(l==i&&r==j){
		cao(nod,de); return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)ins(l,mid,i,j,de,nod<<1); else if(i>mid)ins(mid+1,r,i,j,de,nod<<1|1);
	else{
		ins(l,mid,i,mid,de,nod<<1); ins(mid+1,r,mid+1,j,de,nod<<1|1);
	}
	push_up(nod);
}
void build(int l,int r,int nod){
	if(l==r){tr[nod]=mp(l,l); return;}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
int main(){
	tot=n=read();
	For(i,1,n)p[read()]=read();
	build(1,n,1);
	For(i,1,n){
		while(t1&&p[q1[t1]]>p[i]){
			ins(1,n,q1[t1-1]+1,q1[t1],p[q1[t1]]-p[i],1); t1--;
		}
		while(t2&&p[q2[t2]]<p[i]){
			ins(1,n,q2[t2-1]+1,q2[t2],p[i]-p[q2[t2]],1); t2--;
		}
		q1[++t1]=i; q2[++t2]=i;
		L[i]=tr[1].se; 
	}
	stack<int> st;
	For(i,1,n){
		mn[i]=mx[i]=p[i]; l[i]=r[i]=i; h[i]=0;
		int dq=i;
		while(st.size()){
			int x=st.top(); 
			if(l[x]<L[i])break; 
			if((h[x]==1&&mx[x]+1==mn[dq])||(h[x]==-1&&mn[x]-1==mx[dq])){ 
				cb(x,dq); dq=x; st.pop();
			}else{
				int zs=++tot,cnt=0;
				v[zs].pb(dq); mx[zs]=mx[dq]; mn[zs]=mn[dq]; l[zs]=l[dq]; r[zs]=r[dq]; h[zs]=h[dq];
				while(1){
					int x=st.top(); st.pop();
					cb(zs,x); cnt++; 
					//cout<<mx[zs]<<" "<<mn[zs]<<" "<<l[zs]<<" "<<r[zs]<<endl;
					if(check(zs)){
						if(cnt==1)h[zs]=mx[x]==mx[zs]?-1:1; else h[zs]=0; break;
					}
				}
				dq=zs;
			}
		}
		st.push(dq);
	}
	ll ans=1;
	For(i,n+1,tot){
		int ds=v[i].size();
		if(h[i])ans+=(ll)ds*(ds+1)/2-1; else ans+=ds;
	}
	cout<<ans<<endl;
}