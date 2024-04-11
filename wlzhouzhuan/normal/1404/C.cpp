#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5;

int n,q,a[N],val[N<<2],tag[N<<2],ans[N];

struct query{
	int x,y,id;
	bool operator < (const query &v) const {
		return x>v.x;
	}
}c[N];

void push(int x){
	if(tag[x]){
		val[x<<1]-=tag[x];
		val[x<<1|1]-=tag[x];
		tag[x<<1]+=tag[x];
		tag[x<<1|1]+=tag[x];
		tag[x]=0;
	}
}

void add(int l,int r,int pos,int x,int v){
	if(l==r){
		val[x]=v;
		return;
	} int m=l+r>>1; push(x);
	if(pos<=m)add(l,m,pos,x<<1,v);
	else add(m+1,r,pos,x<<1|1,v);
	val[x]=min(val[x<<1],val[x<<1|1]);
}

int querypos(int l,int r,int x){
	if(l==r&&val[x]>0)return 1e9;
	if(l==r&&val[x]==0)return l;
	int m=l+r>>1,ans; push(x);
	if(val[x<<1|1]==0)ans=querypos(m+1,r,x<<1|1);
	else ans=querypos(l,m,x<<1);
	val[x]=min(val[x<<1],val[x<<1|1]);
	return ans;
}

void modify(int l,int r,int ql,int qr,int x){
	if(ql>qr)return;
	if(ql<=l&&r<=qr){
		val[x]--,tag[x]++;
		return;
	} int m=l+r>>1; push(x);
	if(ql<=m)modify(l,m,ql,qr,x<<1);
	if(m<qr)modify(m+1,r,ql,qr,x<<1|1);
	val[x]=min(val[x<<1],val[x<<1|1]);
}

int d[N];
void add(int x){while(x<=n)d[x]++,x+=x&-x;}
int query(int x){int ans=0; while(x)ans+=d[x],x-=x&-x; return ans;}

void solve(){
	cin>>n>>q;
	memset(val,0x3f,sizeof(val));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=q;i++)cin>>c[i].x>>c[i].y,c[i].id=i;
	sort(c+1,c+q+1);
	int p=1; 
	for(int i=n;i;i--){
		add(1,n,i,1,a[i]>i?1e9:i-a[i]);
		while(val[1]==0){
			int pos=querypos(1,n,1);
			add(pos),add(1,n,pos,1,1e9),modify(1,n,pos+1,n,1);
		}
		while(p<=q&&c[p].x==i-1){
			ans[c[p].id]=query(n-c[p].y);
			p++;
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
}
int main(){
  ios::sync_with_stdio(false),cin.tie(0);
  solve();
}