#include<cstdio>
#include<set>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> PP;

int xs[100100][2];
int ys[100100][2];
int N;

int cxs[100100][2];
int cys[101000][2];

void compress(){
	P ps[200200];
	for(int i=0;i<N;i++){
		ps[i*2]=P(xs[i][0],-i-1);
		ps[i*2+1]=P(xs[i][1],i+1);
	}
	sort(ps,ps+N*2);
//	printf("ps=");
//	for(int i=0;i<N*2;i++) printf("(%d %d)",ps[i].first,ps[i].second);
//	printf("\n");
	for(int i=0;i<N*2;i++){
		int id=ps[i].second;
		if(id<0){
			cxs[-id-1][0]=i+1;
		}else{
			cxs[id-1][1]=i+1;
		}
	}
	for(int i=0;i<N;i++){
		ps[i*2]=P(ys[i][0],-i-1);
		ps[i*2+1]=P(ys[i][1],i+1);
	}
	sort(ps,ps+N*2);
	for(int i=0;i<N*2;i++){
		int id=ps[i].second;
		if(id<0){
			cys[-id-1][0]=i+1;
		}else{
			cys[id-1][1]=i+1;
		}
	}
//	for(int i=0;i<N;i++){
//		printf("%d %d->%d %d\n",cxs[i][0],cys[i][0],cxs[i][1],cys[i][1]);
//	}
}

queue<int> que;

int dis[100100];
int prv[100100];

//PP(P(x,y),(i or -i))

int c=0;

struct BIT{
	set<PP> se[200200];
	int N;
	void init(int N_){
		N=N_;
	}
	void printAll(){
		for(int i=1;i<=N;i++){
			printf("[%d]::\n",i);
			for(set<PP>::iterator it=se[i].begin();it!=se[i].end();it++){
				printf("%d %d %d\n",it->first.first,it->first.second,it->second);
			}
		}
	}
	void ins(PP pp){
		int x=pp.first.second;
		while(x<=N){
			se[x].insert(pp);
			x+=(x&(-x));
		}
	}
	void del(PP pp){
	//	printf("del %d %d %d\n",pp.first.first,pp.first.second,pp.second);
		int x=pp.first.second;
		while(x<=N){
			c++;
	//		if(c>10) exit(0);
	//		printf("%d\n",x);
			se[x].erase(pp);
			x+=(x&(-x));
		}
	}
	void pushAll(int x,int y,int prv_id,queue<int> &que,int d){
//		printf("pushAll %d %d %d\n", x, y, prv_id);
		while(x>0){
			while((!se[x].empty())&&((*se[x].begin()).first.first<=y)){
				PP pp=*se[x].begin();
				if(pp.second<0){
					int id=-pp.second-1;
//					printf("push %d\n", id);
					if(dis[id]==-1){
						dis[id]=d+1;
						prv[id]=prv_id;
						que.push(id);
					}
					del(pp);
				}else{
					del(pp);
				}
			}
			x-=(x&(-x));
		}
	}
};

BIT bit;

void bfs(){
	bit.init(N*2);
//	printf("a\n");
	for(int i=0;i<N;i++){
//		printf("%d %d\n",cxs[i][0],cys[i][0]);
		bit.ins(PP(P(cys[i][0],cxs[i][0]),-i-1));
		bit.ins(PP(P(cys[i][1],cxs[i][1]),i+1));
	}
//	bit.printAll();
//	printf("b\n");
	for(int i=0;i<N;i++){
		dis[i]=-1;
		prv[i]=-1;
	}
	for(int i=0;i<N;i++){
		if(xs[i][0]==0&&ys[i][0]==0){
			dis[i]=1;
			que.push(i);
		}
	}
	while(!que.empty()){
		int id=que.front();
		que.pop();
		bit.pushAll(cxs[id][1],cys[id][1],id,que,dis[id]);
	}
//	printf("bfs end\n");
//	for(int i=0;i<N;i++){
//		printf("%d %d\n",prv[i],dis[i]);
//	}
}

vector<int> ans_path;

void restore(){
	if(dis[N-1]==-1) return;
	int v=N-1;
	while(v!=-1){
		ans_path.push_back(v);
		v=prv[v];
	}
}

void input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&xs[i][0],&ys[i][0],&xs[i][1],&ys[i][1]);
	}
}

int main(){
	input();
	compress();
	bfs();
	restore();
	if(dis[N-1]==-1){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", dis[N-1]);
	for(int i=(int)ans_path.size()-1;i>=0;i--){
		printf("%d%c",ans_path[i]+1,i==0?'\n':' ');
	}
	return 0;
}