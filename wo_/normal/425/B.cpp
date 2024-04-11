#include<cstdio>
#include<algorithm>

using namespace std;

int N,M;
int a[110][110];

int K;

int tmp[110][110];
int flip(){
	for(int i=0;i<N;i++) for(int j=0;j<M;j++){
		tmp[i][j]=a[i][j];
	}
	for(int i=0;i<N;i++) for(int j=0;j<M;j++){
		a[j][i]=tmp[i][j];
	}
	swap(N,M);
}

int get(int stat){
	int res=0;
	for(int i=0;i<N;i++){
		int cnt=0;
		for(int j=0;j<M;j++){
			int x=a[i][j];
			int y=(stat>>j)&1;
			if(x==y) cnt++;
		}
		cnt=min(cnt,M-cnt);
		res+=cnt;
	}
	return res;
}

int get(int *stat){
	int res=0;
	for(int i=0;i<N;i++){
		int cnt=0;
		for(int j=0;j<M;j++){
			int x=stat[j];
			int y=a[i][j];
			if(x==y) cnt++;
		}
		cnt=min(cnt,M-cnt);
		res+=cnt;
	}
	return res;
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++){
		scanf("%d",&a[i][j]);
	}
	if(N<=K){
		flip();
	}
	if(M<=K){
		int ans=-1;
		for(int stat=0;stat<(1<<M);stat++){
			int cur=get(stat);
			if(ans==-1||ans>cur) ans=cur;
		}
		if(ans>K) printf("-1\n");
		else printf("%d\n",ans);
		return 0;
	}
	int tmp[110];
	int ans=-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			tmp[j]=a[i][j];
		}
		int cur=get(tmp);
		if(ans==-1||ans>cur) ans=cur;
	}
	if(ans>K) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}