#include<cstdio>
#include<algorithm>

using namespace std;

struct segtree{
	struct node{
		bool same;
		int val;
		node(){}
		node(int a){
			same=true;
			val=a;
		}
	};
	node nodes[1048576];
	int N;
	void init(int N_){
		N=1;
		while(N<N_) N*=2;
		nodes[1]=node(-1);
	}
	void put(int l,int r,int k,int x,int a,int b){
		if(a<=l&&r<=b){
			nodes[k]=node(x);
			return;
		}else if(r<=a||b<=l) return;
		if(nodes[k].same){
			nodes[k].same=false;
			int v=nodes[k].val;
			nodes[k*2]=node(v);
			nodes[k*2+1]=node(v);
		}
		put(l,(l+r)/2,k*2,x,a,b);
		put((l+r)/2,r,k*2+1,x,a,b);
	}
	int get(int id,int l,int r,int k){
		if(l<=id&&id<r&&nodes[k].same) return nodes[k].val;
		if(id<(l+r)/2) return get(id,l,(l+r)/2,k*2);
		else return get(id,(l+r)/2,r,k*2+1);
	}
	int get(int id){
		return get(id,0,N,1);
	}
	void put(int a,int b,int x){
		if(a==b) return;
		put(0,N,1,x,a,b);
	}
};

segtree seg;

int l[300300],r[300300],x[300300];
int N,M;

int main(){
	scanf("%d%d",&N,&M);
	seg.init(N);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",l+i,r+i,x+i);
		l[i]--;
		r[i]--;
		x[i]--;
	}
	for(int i=M-1;i>=0;i--){
		seg.put(l[i],x[i],x[i]);
		seg.put(x[i]+1,r[i]+1,x[i]);
	}
	for(int i=0;i<N;i++){
		int ans=seg.get(i);
		printf("%d%c",ans+1,i==N-1?'\n':' ');
	}
	return 0;
}