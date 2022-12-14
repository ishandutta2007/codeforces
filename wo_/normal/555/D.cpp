#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

int pre_sort[200200];
map<int,int> pre_sort_id;

int xs[200200];
map<int,int> ids;
int N;

int used_id[200200][2];
int val[200200][2];

int getNxt(int id,int gap){
	int val=xs[id]+gap;
	int id2=lower_bound(xs,xs+N,val)-xs;
	int res=id2-1;
	if(id2<N&&xs[id2]==val) res++;
	//printf("%d %d %d\n",id,gap,res);
	return res;
}

int getPrv(int id,int gap){
	int val=xs[id]-gap;
	int id2=lower_bound(xs,xs+N,val)-xs;
	//printf("%d %d %d\n",id,gap,id2);
	return id2;
}

int solve(int id,int ln,int q){
//	used_id[id][0]=q;
//	val[id][0]=ln;
	int cur_id=id;
	int cur_ln=ln;
	//printf("q=%d\n",q);
	bool le=true;
	while(true){
		//printf("%d %d\n",cur_id,cur_ln);
		bool ed=true;
		if(cur_id!=N-1&&xs[cur_id+1]-xs[cur_id]<=cur_ln) ed=false;
		if(cur_id!=0&&xs[cur_id]-xs[cur_id-1]<=cur_ln) ed=false;
		if(ed) break;
		//printf("process\n");
		if(le){
			int nxt_id=getNxt(cur_id,cur_ln);
			int nxt_ln=cur_ln-(xs[nxt_id]-xs[cur_id]);
			if(used_id[nxt_id][0]==q){
				//printf("b\n");
				int dif=val[nxt_id][0]-nxt_ln;
				if(dif==0) break;
				nxt_ln%=dif;
			}
			used_id[nxt_id][0]=q;
			val[nxt_id][0]=nxt_ln;
			le=false;
			cur_id=nxt_id;
			cur_ln=nxt_ln;
		}else{
			int nxt_id=getPrv(cur_id,cur_ln);
			int nxt_ln=cur_ln-(xs[cur_id]-xs[nxt_id]);
			if(used_id[nxt_id][1]==q){
				int dif=val[nxt_id][1]-nxt_ln;
				if(dif==0) break;
				nxt_ln%=dif;
			}
			used_id[nxt_id][1]=q;
			val[nxt_id][1]=nxt_ln;
			le=true;
			cur_id=nxt_id;
			cur_ln=nxt_ln;
		}
		//printf("a\n");
	}
	return cur_id;
}

int main(){
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",pre_sort+i);
		pre_sort_id[pre_sort[i]]=i;
		xs[i]=pre_sort[i];
	}
	sort(xs,xs+N);
	for(int i=0;i<N;i++) ids[xs[i]]=i;
	for(int i=0;i<200200;i++) for(int j=0;j<2;j++) used_id[i][j]=0;
	for(int q=1;q<=M;q++){
		int id,ln;
		scanf("%d%d",&id,&ln);
		id--;
		int pos=pre_sort[id];
		int id2=ids[pos];
		int ans2=solve(id2,ln,q);
		int ans_pos=xs[ans2];
		int ans=pre_sort_id[ans_pos];
		printf("%d\n",ans+1);
	}
	return 0;
}