#include<cstdio>
#include<algorithm>

using namespace std;

int ans[10][10];

int in[2020][2020];
int nums[4040][4040];

int l[10],r[10],u[10],d[10];

int notes[100100];

int main(){
	int N,M,S,K;
	scanf("%d%d%d%d",&N,&M,&K,&S);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&in[i][j]);
			nums[i+j][j-i+N-1]=in[i][j];
		}
	}
	for(int i=0;i<10;i++){
		l[i]=2*M+2*N,r[i]=-1,u[i]=2*M+2*N,d[i]=-1;
	}
	for(int i=0;i<4040;i++) for(int j=0;j<4040;j++){
		if(nums[i][j]==0) continue;
		int n=nums[i][j];
		l[n]=min(l[n],j);
		r[n]=max(r[n],j);
		u[n]=min(u[n],i);
		d[n]=max(d[n],i);
	}
	for(int i=1;i<=9;i++) for(int j=i;j<=9;j++){
//		if(i==j){
//			ans[i][j]=0;
//			continue;
//		}
		if(r[i]==-1||r[j]==-1) continue;
		ans[i][j]=r[i]-l[j];
		ans[i][j]=max(ans[i][j],r[j]-l[i]);
		ans[i][j]=max(ans[i][j],d[i]-u[j]);
		ans[i][j]=max(ans[i][j],d[j]-u[i]);
		ans[j][i]=ans[i][j];
	}
	int res=0;
	for(int i=0;i<S;i++){
		scanf("%d",notes+i);
	}
	for(int i=1;i<S;i++){
		res=max(res,ans[notes[i-1]][notes[i]]);
	}
/*	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",res);
	return 0;
}