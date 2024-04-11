#include<cstdio>
#include<algorithm>

using namespace std;

int ids[100100];
bool flg[1<<20];

int cnt[20];
int cur_mask;

void ins(int n){
	int id=ids[n];
	cnt[id]++;
	cur_mask|=(1<<id);
}

void del(int n){
	int id=ids[n];
	cnt[id]--;
	if(cnt[id]==0) cur_mask&=(~(1<<id));
}

int N,M,D;

int num[1<<20];

int main(){
	scanf("%d%d%d",&N,&M,&D);
	for(int i=0;i<M;i++){
		int s;
		scanf("%d",&s);
		for(int j=0;j<s;j++){
			int x;
			scanf("%d",&x);
			x--;
			ids[x]=i;
		}
	}
	for(int i=0;i<D;i++) ins(i);
	flg[cur_mask]=true;
	for(int i=1;i+D-1<N;i++){
		del(i-1);
		ins(i+D-1);
		flg[cur_mask]=true;
	}
	for(int i=0;i<(1<<M);i++) num[i]=flg[i]?1:0;
	for(int i=0;i<M;i++) for(int j=0;j<(1<<M);j++){
		if((j>>i)&1){
			num[j]+=num[j^(1<<i)];
		}
	}
	int ans=M;
	for(int i=0;i<(1<<M);i++){
		if(num[i]==0){
			int cnt=0;
			for(int j=0;j<M;j++) if((i>>j)&1) cnt++;
			ans=min(ans,M-cnt);
		}
	}
	printf("%d\n",ans);
	return 0;
}