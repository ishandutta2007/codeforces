#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=50005,M=37180;
using node=bitset<165>;
using LL=long long;
int n;
LL ans[N];
vector<tuple<LL,LL,int> >vec[11];
struct node_cmp{
	bool operator()(const node&lhs,const node&rhs)const{
		node tmp=lhs^rhs;
		int pos=tmp._Find_first();
		if(pos<165)return lhs[pos]<rhs[pos];
		else return 0;
	}
};
map<node,int,node_cmp>mp;
int len,dis[M],go[M][10];
node pool[M];
int get_id(const node&cur){
	if(mp.count(cur))return mp[cur];
	else return pool[++len]=cur,mp[cur]=len;
}
node new_node(node&cur,int x){
	return cur|(cur<<x);
}
void gen_node(){
	queue<int>q;
	{
		node start;
		start.reset();
		start.set(0);
		int u=get_id(start);
		dis[u]=0;
		q.push(u);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(dis[u]>=18)break;
		rep(i,1,9){
			node nex(new_node(pool[u],i));
			int v=get_id(nex);
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	rep(i,1,len)if(dis[i]<18){
		rep(x,0,9){
			go[i][x]=get_id(new_node(pool[i],x));
		}
	}
}
LL dp[M][20];
void gen_dp(int k){
	memset(dp,0,sizeof(dp));
	rep(i,1,len){
		int t=164;
		while(!pool[i][t])--t;
		int t_=t>>1;
		while(!pool[i][t_])--t_;
		dp[i][0]=abs(t_-(t-t_))<=k;
	}
	rep(j,1,18){
		rep(i,1,len){
			rep(x,0,9){
				dp[i][j]+=dp[go[i][x]][j-1];
			}
		}
	}
}
int num[20],top;
LL query(LL rr,int k){
	top=0;
	while(rr){
		num[++top]=rr%10;
		rr/=10;
	}
	LL res=0;
	int u=1;
	per(i,top,1){
		rep(x,0,num[i]-1){
			res+=dp[go[u][x]][i-1];
		}
		u=go[u][num[i]];
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(dis,63,sizeof(dis));
	scanf("%d",&n);
	rep(i,1,n){
		LL l,r;
		int k;
		scanf("%lld%lld%d",&l,&r,&k);
		vec[k].eb(l,r,i);
	}
	gen_node();
	rep(k,0,9){
		gen_dp(k);
		for(auto&_:vec[k]){
			LL l,r,id;
			tie(l,r,id)=_;
			ans[id]=query(r+1,k)-query(l,k);
		}
	}
	rep(i,1,n)printf("%lld\n",ans[i]);
	return 0;
}