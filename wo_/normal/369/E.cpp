#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

struct segtree{
	int N;
	int dep;
	int dat[21][1048576];
	void init(int *a,int N_){
		N=1;
		dep=0;
		while(N<N_){
			N*=2;
			dep++;
		}
		for(int i=0;i<N_;i++){
			dat[dep][i]=a[i];
		}
		for(int i=N_;i<N;i++){
			dat[dep][i]=-1;
		}
		int ln=1;
		for(int d=dep-1;d>=0;d--){
			ln*=2;
			for(int l=0;l+ln<=N;l+=ln){
				int r=l+ln;
				int lid=l,rid=l+ln/2;
				for(int id=l;id<r;id++){
					if(lid==l+ln/2){
						dat[d][id]=dat[d+1][rid++];
					}else if(rid==r){
						dat[d][id]=dat[d+1][lid++];
					}else{
						if(dat[d+1][lid]<dat[d+1][rid]){
							dat[d][id]=dat[d+1][lid++];
						}else{
							dat[d][id]=dat[d+1][rid++];
						}
					}
				}
			}
		}
	}
	int get_(int l,int r,int x,int d,int a,int b){
		if(l<=a&&b<=r){
			return upper_bound(&dat[d][a],&dat[d][b],x)-(&dat[d][a]);
		}else if(r<=a||b<=l) return 0;
		return get_(l,r,x,d+1,a,(a+b)/2)+get_(l,r,x,d+1,(a+b)/2,b);
	}
	int get_(int l,int r,int x){
		return get_(l,r,x,0,0,N);
	}
	int get(int l,int r,int x){
		int total=r-l;
		return total-get_(l,r,x-1);
	}
};

segtree seg;

map<int,int> cnt;

int nums[300300];
int ls[300300],rs[300300];
int cls[300300];
int N;
int a[300300];

void compress(){
	for(int i=0;i<N;i++){
		nums[i]=ls[i];
	}
	sort(nums,nums+N);
	for(int i=0;i<N;i++){
		int tmp=lower_bound(nums,nums+N,ls[i])-nums;
		tmp+=cnt[ls[i]];
		cnt[ls[i]]++;
		cls[i]=tmp;
	}
	for(int i=0;i<N;i++){
		a[cls[i]]=rs[i];
	}
}

void init(){
	seg.init(a,N);
}

int qln;
int query[300300];

int solve(){
	int l=0,r;
	int res=0;
	for(int i=0;i<qln;i++){
		if(i!=0){
			l=r+1;
		}
		r=upper_bound(nums,nums+N,query[i])-nums-1;
		res+=seg.get(l,r+1,query[i]);
	}
	return res;
}

int main(){
	int Q;
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++){
		scanf("%d%d",ls+i,rs+i);
	}
	compress();
	init();
	for(int i=0;i<Q;i++){
		scanf("%d",&qln);
		for(int j=0;j<qln;j++){
			scanf("%d",query+j);
		}
		printf("%d\n",solve());
	}
	return 0;
}