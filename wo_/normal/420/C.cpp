#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct BIT{
	int N;
	int dat[600600];
	void init(int N_){
		N=N_;
		for(int i=0;i<=N;i++) dat[i]=0;
	}
	void add(int i,int x){
		while(i<=N){
			dat[i]+=x;
			i+=(i&(-i));
		}
	}
	int get(int i){
		int res=0;
		while(i>0){
			res+=dat[i];
			i-=(i&(-i));
		}
		return res;
	}
};

int N;
vector<int> p[300300];
int req;

struct Solver{
	BIT bit;
	int cnt[300300];
	void inc(int id){
		if(cnt[id]>0) bit.add(cnt[id],-1);
		cnt[id]++;
		if(cnt[id]==0) printf("inc\n");
		bit.add(cnt[id],1);
	}
	void dec(int id){
		int n=cnt[id];
		if(cnt[id]==0) printf("dec%d\n",id);
		bit.add(cnt[id],-1);
		cnt[id]--;
		if(cnt[id]>0) bit.add(cnt[id],1);
	}
	void init(int N){
		for(int i=0;i<=N;i++) cnt[i]=0;
		bit.init(N*2);
		for(int i=1;i<=N;i++){
			for(int j=0;j<p[i].size();j++){
				int u=i,v=p[i][j];
				inc(u);
				inc(v);
			}
		}
//		for(int i=1;i<=N*2;i++){
//			printf("%d ",bit.get(i)-bit.get(i-1));
//		}
//		printf("\n");
	}
	int get(int id){
		for(int i=0;i<p[id].size();i++){
			int u=id,v=p[id][i];
			dec(u);
			dec(u);
			dec(v);
			dec(v);
		}
		int x=p[id].size();
		int cur=max(req-x,0);
		int res=bit.get(cur*2-1);
		res=bit.get(N*2)-res;
		for(int i=0;i<p[id].size();i++){
			int u=id,v=p[id][i];
			inc(u);
			inc(u);
			inc(v);
			inc(v);
		}
	//	printf("%d %d\n",id,res);
		return cur==0?N-1:res;
	}
	long long get(){
		long long res=0;
		for(int i=1;i<=N;i++){
			res+=get(i);
		}
		return res/2;
	}
};

Solver sol;

int main(){
	scanf("%d%d",&N,&req);
	for(int i=0;i<N;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		p[u].push_back(v);
		p[v].push_back(u);
	}
	sol.init(N);
	long long res=sol.get();
	cout<<res<<"\n";
	return 0;
}