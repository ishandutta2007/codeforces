#include<cstdio>
#include<cassert>
#include<algorithm>

using namespace std;

int SZ;
int M;

struct BIT{
	int dat[2002000];
	int N;
	void init(int N_){
		N=N_;
		for(int i=0;i<=N;i++) dat[i]=0;
	}
	void add(int i,int x){
//		assert(i>0);
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
	void output(){
		for(int i=1;i<=N;i++){
			printf("%d ",get(i)-get(i-1));
		}
		printf("\n");
	}
};

struct Arr{
	BIT bit;
	int num[2002000];
	int N;
	void init(int N_){
		N=N_;
		bit.init(SZ);
		for(int i=0;i<=M;i++) num[i]=-1;
		for(int i=M+1;i<=N+M;i++) num[i]=i-M;
		for(int i=M+1;i<=N+M;i++) bit.add(i,1);
	}
	int getNth(int n){
		int cur=0;
		int k=1;
		while(k<SZ) k*=2;
		if(n<=0) return 0;
		int res=0;
		for(;k>0;k/=2){
			if(res+k<=SZ&&cur+bit.dat[res+k]<n){
				cur+=bit.dat[res+k];
				res+=k;
			}
		}
		return res+1;
	}
	int changeNth(int n){
		int from=getNth(n);
		int to=getNth(1)-1;
		int curNum=num[from];
		assert(curNum>=1&&curNum<=N);
		num[from]=-1;
		num[to]=curNum;
		bit.add(from,-1);
		bit.add(to,1);
//		bit.output();
		return curNum;
	}
};

Arr arr;

int x[1001000],y[1001000];

int ans[1001000];

bool used[1001000];

int main(){
	int N;
	scanf("%d%d",&N,&M);
	SZ=N+M;
	for(int i=0;i<M;i++) scanf("%d%d",x+i,y+i);
	arr.init(N);
	for(int i=1;i<=N;i++) ans[i]=-1;
	bool ok=true;
	for(int i=0;i<M;i++){
		int num=arr.changeNth(y[i]);
		if(ans[num]==-1||ans[num]==x[i]) ans[num]=x[i];
		else ok=false;
	}
	if(ok==false){
		printf("-1\n");
		return 0;
	}else{
		for(int i=1;i<=N;i++) used[i]=false;
		bool flg=true;
		for(int i=1;i<=N;i++) if(ans[i]!=-1){
			if(used[ans[i]]==true) flg=false;
			used[ans[i]]=true;
		}
		if(flg==false){
			printf("-1\n");
			return 0;
		}
		int id=1;
/*		printf("\"");
		for(int i=1;i<=N;i++) printf("%d ",ans[i]);
		printf("\"\n");*/
		for(int i=1;i<=N;i++){
			int tmp;
			if(ans[i]!=-1) tmp=ans[i];
			else{
				while(used[id]==true) id++;
				tmp=id;
				used[id]=true;
			}
			printf("%d%c",tmp,i==N?'\n':' ');
		}
	}
	return 0;
}