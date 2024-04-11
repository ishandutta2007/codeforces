#include<stdio.h>
#include<vector>
#include<algorithm>
#define MN 2001
#define MM 2001

using namespace std;

struct EDGE{
	int t;
	__int64 c;
}pushv;

struct HEAP{
	int n;
	__int64 v;
}pv,top,heap[10*MM];

int N,M;
int s,e;
int H,v[MN];
__int64 D[MN],txc[MN],txd[MN];

vector<EDGE>E[MN];
vector<EDGE>nE[MN];

bool cmp(HEAP a,HEAP b){
	if(a.v>b.v)return 1;
	return 0;
}

void push(int n,__int64 v){
	pv.n=n,pv.v=v;
	heap[H++]=pv;
	push_heap(heap,heap+H,cmp);
}

void pop(){
	pop_heap(heap,heap+H,cmp);
	heap[--H].n=heap[H].v=0;
}

int main()
{
	int i,a,b,c,j,k;
	scanf("%d%d",&N,&M);
	scanf("%d%d",&s,&e),--s,--e;
	for(i=0;i<M;i++){
		scanf("%d%d%I64d",&a,&b,&c),--a,--b;
		pushv.t=b,pushv.c=c;
		E[a].push_back(pushv);
		pushv.t=a,pushv.c=c;
		E[b].push_back(pushv);
	}
	for(i=0;i<N;i++){
		scanf("%I64d%I64d",txd+i,txc+i);
	}
	for(j=0;j<N;j++){
		for(i=0;i<N;i++)D[i]=(__int64)1e15;
		for(i=0;i<N;i++)v[i]=0;
		while(H)pop();
		D[j]=0;
		push(j,0);
		for(k=0;k<N;k++){
			while(H && v[heap[0].n])pop();
			if(!H)break;
			top=heap[0];
			pop();
			v[top.n]=1;
			for(i=0;i<E[top.n].size();i++){
				if(D[E[top.n][i].t]>D[top.n]+E[top.n][i].c){
					D[E[top.n][i].t]=D[top.n]+E[top.n][i].c;
					push(E[top.n][i].t,D[E[top.n][i].t]);
				}
			}
		}
		for(i=0;i<N;i++){
			if(D[i]<=txd[j] && i!=j){
				pushv.t=i;
				pushv.c=txc[j];
				nE[j].push_back(pushv);
			}
		}
	}
	for(i=0;i<N;i++)D[i]=(__int64)1e15;
	for(i=0;i<N;i++)v[i]=0;
	while(H)pop();
	D[s]=0;
	push(s,0);
	for(k=0;k<N;k++){
		while(H && v[heap[0].n])pop();
		if(!H)break;
		top=heap[0];
		pop();
		v[top.n]=1;
		for(i=0;i<nE[top.n].size();i++){
			if(D[nE[top.n][i].t]>D[top.n]+nE[top.n][i].c){
				D[nE[top.n][i].t]=D[top.n]+nE[top.n][i].c;
				push(nE[top.n][i].t,D[nE[top.n][i].t]);
			}
		}
	}
	if(D[e]==(__int64)1e15){
		printf("-1");
		return 0;
	}
	printf("%I64d",D[e]);
	return 0;
}