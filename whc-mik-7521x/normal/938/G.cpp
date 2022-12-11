#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Linear_base{
	long long base[70];
	Linear_base(){memset(base,0,sizeof base);}
	void insert(long long x) {
		for(int i=55;i+1;i--){
			if(!(x>>i))continue;
			if(!base[i]){
				base[i]=x;
				break;
			}
			x^=base[i];
		}
	}
	long long query(long long x){
		for(int i=55;i+1;i--){
			if(!(x&(1<<i))||!base[i])continue;
			x^=base[i];
		}
		return x;
	}
}ty;
struct dsu{
	struct ope{
		int x,fa,dis,siz,tim;
	};
	stack<ope>stk;
	int dis[N],fa[N],siz[N];
	dsu(){for(int i=0;i<N;i++)dis[i]=0,fa[i]=i,siz[i]=1;}
	int find(int x){
		if(x==fa[x])return x;
		return find(fa[x]);
	}
	int find_dis(int x){
		if(x==fa[x])return dis[x];
		return find_dis(fa[x])^dis[x];
	}
	void unnion(int x,int y,int tim,int di){
		int xx=find(x),yy=find(y);
		if(xx==yy){
			ty.insert(find_dis(x)^find_dis(y)^di);
		}
		else{
			ope k1={xx,fa[xx],dis[xx],siz[xx],tim},k2={yy,fa[yy],dis[yy],siz[yy],tim};
			if(siz[xx]>=siz[yy]){
				fa[yy]=xx;
				dis[yy]=find_dis(x)^find_dis(y)^di;
				siz[xx]+=siz[yy];
			}
			else{
				fa[xx]=yy;
				dis[xx]=find_dis(x)^find_dis(y)^di;
				siz[yy]+=siz[xx];
			}
			stk.push(k1);
			stk.push(k2);
		}
	}
	void rt(int tim){
		while(stk.size()&&stk.top().tim==tim){
			ope now=stk.top();
			stk.pop();
			dis[now.x]=now.dis;
			fa[now.x]=now.fa;
			siz[now.x]=now.siz;
		}
	}
}sb1;
struct node{
	int x,y,d;
};
int qx[N],qy[N];
struct seg{
	vector<node>t[N<<2];
	void upd(int rt,int l,int r,int L,int R,node d){
		if(L>R)return;
		if(L<=l&&r<=R)return t[rt].push_back(d);
		int mid=(l+r)>>1;
		if(mid>=L)upd(rt<<1,l,mid,L,R,d);
		if(mid<R)upd(rt<<1|1,mid+1,r,L,R,d);
	}
	void dfs(int rt,int l,int r){
		Linear_base now=ty;
		for(auto it:t[rt]){
			sb1.unnion(it.x,it.y,rt,it.d);
		}
		if(l==r){printf("%lld\n",ty.query(sb1.find_dis(qx[l])^sb1.find_dis(qy[l])));sb1.rt(rt),ty=now;return;}
		int mid=(l+r)>>1;
		dfs(rt<<1,l,mid);
		dfs(rt<<1|1,mid+1,r);
		sb1.rt(rt);
		ty=now;
	}
}sb2;
map<pair<int,int>,pair<int,int>>mp;
struct inb{
	int x,y,tp,val;
}que[N];
int n,m,q,tot;
int main(){
	scanf("%d%d",&n,&m);
	int tim=1;
	for(int i=1;i<=m;i++){
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		int xx=min(x,y),yy=max(x,y);
		mp[{xx,yy}]={tim,val};
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int tp,x,y,val;
		scanf("%d%d%d",&tp,&x,&y);
		int xx=min(x,y),yy=max(x,y);
		if(tp==3){
			que[i]={xx,yy,tp,0};
			tot++;
		}
		if(tp==2){
			que[i]={xx,yy,tp,0};
		}
		if(tp==1){
			scanf("%d",&val);
			que[i]={xx,yy,tp,val};
		}
	}
	for(int i=1;i<=q;i++){
		if(que[i].tp==3){
			qx[tim]=que[i].x,qy[tim]=que[i].y;
			tim++;
		}
		if(que[i].tp==2){
			sb2.upd(1,1,tot,mp[{que[i].x,que[i].y}].first,tim-1,node{que[i].x,que[i].y,mp[{que[i].x,que[i].y}].second});
			mp.erase({que[i].x,que[i].y});
		}
		if(que[i].tp==1){
			mp[{que[i].x,que[i].y}]={tim,que[i].val};
		}
	}
	for(auto it:mp){
		sb2.upd(1,1,tot,it.second.first,tot,node{it.first.first,it.first.second,it.second.second});
	}
	sb2.dfs(1,1,tot);
	return  0;
}