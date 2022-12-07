#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

struct edge{
	int x,y,v;
	bool operator <(const edge &a)const{
		if (v!=a.v) return v<a.v;
		if (x!=a.x) return x<a.x;
		return y<a.y;
	}
	bool operator ==(const edge &a)const{
		return x==a.x&&y==a.y&&v==a.v;
	}
};
const int N=100005;
int n,m,Q;
pair<int,int> mn[N];
map<pair<int,int>,int> mp;
set<pair<long long,int>> val;
set<edge> S[N];
set<edge> E;

void recov(int x,int mode){
	int rem=3;
	long long sum=0;
	set<edge>::iterator it=S[x].begin();
	for (;rem&&it!=S[x].end();--rem,++it){
		sum+=it->v;
		pair<int,int> info(it->v,x);
		if (info<=mn[it->y]){
			if (mode==-1) E.erase((edge){min(it->x,it->y),max(it->x,it->y),it->v});
			if (mode==1) E.insert((edge){min(it->x,it->y),max(it->x,it->y),it->v});
		}
	}
	if (rem==0){
		--it;
		if (mode==-1) val.erase(pair<long long,int>(sum,x));
		if (mode==1) val.insert(pair<long long,int>(sum,x));
		mn[x]=pair<int,int>(it->v,it->x+it->y-x);
	}
	else
		mn[x]=pair<int,int>(1<<30,1<<30);
}
void insert(int x,int y,int v){
	mp[pair<int,int>(x,y)]=v;


	recov(x,-1);
	S[x].insert((edge){x,y,v});
	recov(x,1);
	
	swap(x,y);
	
	recov(x,-1);
	S[x].insert((edge){x,y,v});
	recov(x,1);
}
void erase(int x,int y){
	int v=mp[pair<int,int>(x,y)];
	
	recov(x,-1);
	S[x].erase((edge){x,y,v});
	recov(x,1);
	
	swap(x,y);
	
	recov(x,-1);
	S[x].erase((edge){x,y,v});
	recov(x,1);
}

long long ask(){
	long long ans=1ll<<40;
	edge e=*E.begin();
	set<edge>::iterator ita,itb;
	int rem1,rem2,rem=15;
	for (ita=E.begin();ita!=E.end()&&rem;--rem,++ita)
		if (ita->x!=e.x&&ita->x!=e.y&&ita->y!=e.x&&ita->y!=e.y){
			ans=min(ans,1ll*ita->v+e.v);
			break;
		}
	
	rem1=3;
	ita=S[e.x].begin();
	for (;ita!=S[e.x].end()&&rem1;++ita,--rem1){
		rem2=3;
		itb=S[e.y].begin();
		for (;itb!=S[e.y].end()&&rem2;++itb,--rem2)
			if (ita->x!=itb->x&&ita->y!=itb->y&&ita->x!=itb->y&&ita->y!=itb->x)
				ans=min(ans,1ll*ita->v+itb->v);
	}
	if (!val.empty())
		ans=min(ans,val.begin()->first);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		mn[i]=pair<int,int>(1<<30,1<<30);
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if (x>y) swap(x,y);
		insert(x,y,v);
	}
	printf("%lld\n",ask());
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		int tp,x,y,v;
		scanf("%d%d%d",&tp,&x,&y);
		if (x>y) swap(x,y);
		if (tp==0)
			erase(x,y);
		else{
			scanf("%d",&v);
			insert(x,y,v);
		}
		printf("%lld\n",ask());
	}
}