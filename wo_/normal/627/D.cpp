#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int m,head[200200],to[400400],nxt[400400];
int from[400400];

void init_edge(){
	m=0;
	for(int i=0;i<200200;i++){
		head[i]=-1;
	}
}

void add_edge(int u,int v){
	nxt[m]=head[u];to[m]=v;from[m]=u;head[u]=m;m++;
	nxt[m]=head[v];to[m]=u;from[m]=v;head[v]=m;m++;
}

int N;
int K;
int cost[200200];
int par_e[200200];
int v_ord[200200];

int sum_ret[200200];
int ma_no_ret[200200][2];
P state[400400];
//(x,1):visit x vertices and return
//(x,-1):visit x vertices and do not return

bool used[200200];
int C;

void init_check(){
	for(int i=0;i<200200;i++){
		par_e[i]=-1;
		used[i]=false;
	}
	for(int i=0;i<400400;i++){
		state[i]=P(-1,-1);
	}
}

vector<int> e_ids;
void dfs(int v,int p,int e_id){
	used[v]=true;
	if(cost[v]<C){
		state[e_id]=P(0,-1);
		return;
	}
	par_e[v]=e_id;
	if(e_id!=-1) e_ids.push_back(e_id);
	sum_ret[v]=0;
	for(int i=0;i<2;i++) ma_no_ret[v][i]=-1;
	for(int e=head[v];e!=-1;e=nxt[e]){
		if(to[e]==p) continue;
		dfs(to[e],v,e);
		P p=state[e];
		if(p.second==-1){
			int x=p.first;
			if(ma_no_ret[v][0]<x){
				ma_no_ret[v][1]=ma_no_ret[v][0];
				ma_no_ret[v][0]=x;
			}else if(ma_no_ret[v][1]<x){
				ma_no_ret[v][1]=x;
			}
		}else{
			int x=p.first;
			sum_ret[v]+=x;
		}
	}
	//calc state[e_id]
	if(e_id!=-1){
		if(ma_no_ret[v][0]==-1){
			state[e_id]=P(sum_ret[v]+1,1);
		}else{
			state[e_id]=P(sum_ret[v]+1+ma_no_ret[v][0],-1);
		}
	}
}

void calc_rev(bool debug=false){
	for(auto e:e_ids){
		//calc state[e^1]
		int p=from[e];
		int v=to[e];
		if(cost[p]<C){
			state[e^1]=P(-1,-1);
			continue;
		}
		int cur_sum_ret=sum_ret[p];
		int cur_ma_no_ret=ma_no_ret[p][0];
		P st=state[e];
		if(debug){
			printf("e=%d %d,st=%d %d cur_sum_ret=%d cur_ma_no_ret=%d\n",from[e],to[e],st.first,st.second,cur_sum_ret,cur_ma_no_ret);
		}
		if(st.second==-1&&cur_ma_no_ret==st.first){
			cur_ma_no_ret=ma_no_ret[p][1];
		}else{
			cur_sum_ret-=st.first;
		}
		if(debug) printf("%d %d\n",cur_sum_ret,cur_ma_no_ret);
		int pe=par_e[p];
		if(pe!=-1){
			P st_p=state[pe^1];
			if(st_p.second==-1){
				if(cur_ma_no_ret<st_p.first){
					cur_ma_no_ret=st_p.first;
				}
			}else{
				cur_sum_ret+=st_p.first;
			}
		}
		if(debug) printf("%d %d\n",cur_sum_ret,cur_ma_no_ret);
		if(cur_ma_no_ret==-1){
			state[e^1]=P(cur_sum_ret+1,1);
		}else{
			state[e^1]=P(cur_sum_ret+1+cur_ma_no_ret,-1);
		}
		if(debug)printf("%d %d\n",state[e^1].first,state[e^1].second);
	}
}

bool check(int C_,bool debug=false){
	C=C_;
	init_check();
	for(int i=0;i<N;i++){
		int v=v_ord[i];
		if(used[v]) continue;
		if(cost[v]<C) continue;
		e_ids.clear();
		dfs(v,-1,-1);
		calc_rev(debug);
	}
	if(debug){
		for(int i=0;i<(N-1)*2;i++){
			int u=from[i],v=to[i];
			int x=state[i].first,y=state[i].second;
			printf("%d->%d:: %d %d\n",u,v,x,y);
		}
	}
	int best=1;/*
	for(int i=0;i<(N-1)*2;i++){
		best=max(best,state[i].first+1);
	}*/
	for(int v=0;v<N;v++){
		if(cost[v]<C) continue;
		int tmp=0;
		int tmp2=0;
		for(int e=head[v];e!=-1;e=nxt[e]){
			if(state[e]==P(-1,-1)) continue;
			if(state[e].second==-1) tmp2=max(tmp2,state[e].first);
			if(state[e].second==1) tmp+=state[e].first;
		}
		best=max(best,tmp+tmp2+1);
		if(debug&&tmp+tmp2+1==K){
			printf("%d\n",v);
		}
	}
	if(debug){
		for(int i=0;i<N;i++){
			printf("%d %d\n",i,sum_ret[i]);
		}
	}
	return best>=K;
}

int solve(){
	int lb=1,ub=cost[v_ord[0]]+1;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		bool flg=check(mid);
		if(flg) lb=mid;
		else ub=mid;
	}
	return lb;
}

void input(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",cost+i);
	}
	init_edge();
	for(int i=0;i<N-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		add_edge(u,v);
	}
	int largest_c=-1;
	int largest_v=-1;
	for(int i=0;i<N;i++){
		if(largest_c<cost[i]){
			largest_c=cost[i];
			largest_v=i;
		}
		v_ord[i]=i;
	}
	swap(v_ord[0],v_ord[largest_v]);
}

int main(){
	input();
	int ans=solve();
	printf("%d\n",ans);
	return 0;
}