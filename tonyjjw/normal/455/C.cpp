#include<stdio.h>
#include<vector>
#include<queue>
#define MAX(a,b)((a)>(b)?(a):(b))
#define MN 300010

using namespace std;

//#pragma warning(disable:4996)

int N,M,Q;
int p[MN],V[MN],D[MN];
vector<int> E[MN];
queue<int> QU;

int par(int n){
	if(p[n]==-1)return n;
	p[n]=par(p[n]);
	return p[n];
}

int main(){
	int i,j,a,b,h;
//	freopen("input.txt","r",stdin);
	scanf("%d%d%d",&N,&M,&Q);
	for(i=0;i<N;i++)p[i]=-1;
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b),--a,--b;
		p[par(a)]=par(b);
		E[a].push_back(b),E[b].push_back(a);
	}
	for(i=0;i<N;i++){
		if(V[i])continue;
		QU.push(i),V[i]=1;
		while(!QU.empty()){
			h=QU.front(),QU.pop();
			for(j=0;j<E[h].size();j++){
				if(V[E[h][j]])continue;
				QU.push(E[h][j]),V[E[h][j]]=1;
			}
		}
		QU.push(h),V[h]=2,D[h]=0;
		while(!QU.empty()){
			h=QU.front(),QU.pop();
			for(j=0;j<E[h].size();j++){
				if(V[E[h][j]]==2)continue;
				QU.push(E[h][j]),V[E[h][j]]=2,D[E[h][j]]=D[h]+1;
			}
		}
		D[par(i)]=D[h];
	}
	for(i=0;i<Q;i++){
		scanf("%d",&h);
		if(h==1){
			scanf("%d",&a),--a;
			printf("%d\n",D[par(a)]);
		}
		else{
			scanf("%d%d",&a,&b),--a,--b;
			a=par(a),b=par(b);
			if(a==b)continue;
			D[a]=MAX(D[a],MAX(D[b],(D[a]+1)/2+(D[b]+1)/2+1));
			p[b]=a;
		}
	}
	return 0;
}