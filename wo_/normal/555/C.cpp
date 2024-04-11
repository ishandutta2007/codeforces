#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=1e9;

struct Segtree{
	int N;
	int dat[524288];
	void init(int N_,int val){
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++) dat[i]=val;
	}
	void update(int l,int r,int x,int k,int a,int b){
		if(r<=a||b<=l) return;
		if(l<=a&&b<=r){
			dat[k]=max(dat[k],x);
			return;
		}
		update(l,r,x,k*2,a,(a+b)/2);
		update(l,r,x,k*2+1,(a+b)/2,b);
	}
	void update(int l,int r,int x){
		update(l,r,x,1,0,N);
	}
	int get(int id){
		id+=N;
		int res=-inf;
		while(id>=1){
			res=max(res,dat[id]);
			id/=2;
		}
		return res;
	}
};

Segtree LSeg,USeg;

int vals[200200];
int ln;
int N;

inline int get_id(int x){
	return lower_bound(vals,vals+ln,x)-vals;
}

int qi[200200],qj[200200];
char qc[200200];
int Q;

int UQuery(int i){
	int j=USeg.get(i);
	j*=-1;
	int ans=vals[j]-vals[i];
	LSeg.update(i,j+1,i);
	return ans;
}

int LQuery(int i){
	int j=LSeg.get(i);
	int ans=vals[i]-vals[j];
	USeg.update(j,i+1,-i);
	return ans;
}

bool used_L[200200],used_U[200200];

int main(){
	scanf("%d%d",&N,&Q);
	for(int i=0;i<Q;i++){
		scanf("%d%d",qj+i,qi+i);
		char ch[10];
		scanf("%s",ch);
		qc[i]=ch[0];
		vals[i]=qj[i];
	}
	vals[Q]=0;
	vals[Q+1]=N+1;
	sort(vals,vals+Q+2);
	ln=unique(vals,vals+Q+2)-vals;
	LSeg.init(ln,0);
	USeg.init(ln,-(ln-1));
	for(int q=0;q<Q;q++){
		int num=qj[q];
		int i=get_id(num);
		if(qc[q]=='L'){
			if(used_L[i]){
				printf("0\n");
				continue;
			}
			used_L[i]=true;
			int ans=LQuery(i);
			printf("%d\n",ans);
		}else{
			if(used_U[i]){
				printf("0\n");
				continue;
			}
			used_U[i]=true;
			int ans=UQuery(i);
			printf("%d\n",ans);
		}
	}
	return 0;
}