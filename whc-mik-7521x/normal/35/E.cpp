#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int n,m,sum[N<<2],lazy[N<<2],rma;
int ri[N],li[N],hi[N],to[N<<2];

//void built(int l,int r,int rt){
//	if(l==r){
//		scanf("%lld",&sum[rt]);
//		return;
//	}
//	int mid=(l+r)>>1;
//	built(l,mid,rt<<1);
//	built(mid+1,r,rt<<1|1);
//	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
//}

void pu(int l,int r,int rt){
	lazy[rt<<1]=max(lazy[rt],lazy[rt<<1]);
	lazy[rt<<1|1]=max(lazy[rt<<1|1],lazy[rt]);
	lazy[rt]=0;
}

void upd(int l,int r,int rt,int L,int R,int d){
	if(L<=l&&r<=R){
		lazy[rt]=max(d,lazy[rt]);
		return;
	}
	pu(l,r,rt);
	int mid=(l+r)>>1;
	if(mid>=L)upd(l,mid,rt<<1,L,R,d);
	if(mid<R)upd(mid+1,r,rt<<1|1,L,R,d);
}

int query(int l,int r,int rt,int L,int R){
	if(l==r)return lazy[rt];
	int mid=(r+l)>>1;
	pu(l,r,rt);
	if(mid>=L)return query(l,mid,rt<<1,L,R);
	if(mid<R)return query(mid+1,r,rt<<1|1,L,R);
	return 0;
}

signed main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector<int>v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&hi[i],&li[i],&ri[i]);
		v.push_back(ri[i]);
		v.push_back(li[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		int ln=lower_bound(v.begin(),v.end(),li[i])-v.begin()+1;
		int rn=lower_bound(v.begin(),v.end(),ri[i])-v.begin()+1;
		to[ln]=li[i];
		to[rn]=ri[i];
		li[i]=ln;
		ri[i]=rn;
		rma=max(rma,li[i]);
		rma=max(rma,ri[i]);
	}
	for(int i=1;i<=n;i++){
		upd(1,rma,1,li[i],ri[i]-1,hi[i]);
	}
	int last=0,ans=0;
	vector<int>q;
	for(int i=1;i<=rma;i++){
		int now=query(1,rma,1,i,i);
		if(last!=now){
			ans+=2;
			q.push_back(to[i]);
			q.push_back(last);
			q.push_back(to[i]);
			q.push_back(now);
			last=now;
		}
	}
	printf("%d\n",ans); 
	for(int i=0;i<q.size();i+=2){
		printf("%d %d\n",q[i],q[i+1]);
	}
	return 0;
}