#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

//string str;
//string ans;
char str[1100100],ans[1100100];
int nxt[1100100][22];
int N,D,K;
int to[1100100];
int LOGN;

void setNxt(){
	for(int j=1;j<LOGN;j++){
		for(int i=0;i<K;i++){
			if(nxt[i][j-1]==-1) nxt[i][j]=-1;
			else nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		}
	}
}

int countToNegative(int id){
	int res=0;
//	if(K==4) printf("%d,",id);
	for(int j=LOGN-1;j>=0;j--){
		if(nxt[id][j]==-1) continue;
		else{
			id=nxt[id][j];
			res|=(1<<j);
		}
	}
//	if(K==4) printf("%d\n",res+1);
	return res+1;
}

int traceNTimes(int id,int n){
	int res=id;
	for(int j=LOGN-1;j>=0;j--){
		if((n&(1<<j))==0) continue;
		else res=nxt[res][j];
	}
	return res;
}

int get(int id){
//	printf("%d::",id);
	if(id<K){
		int t=countToNegative(id);
		if(!(t+K-2<=N-1)){
			int num=N-K+1;
			int res=traceNTimes(id,num);
//			printf("a,%d\n",N-K+res);
			return N-K+res+1;
		}else{
//			printf("b,%d\n",t-1);
			return t-1;
		}
	}else{
		int t=countToNegative(K-1);
		if(!(id+t<=N-1)){
			int num=N-id;
			int res=traceNTimes(K-1,num);
//			printf("c,%d\n",N-K+res);
			return N-K+res+1;
		}else{
//			printf("d,%d\n",id-K+1+t-1);
			return id-K+1+t-1;
		}
	}
}

void solve(){
	int c=-1;
	for(int r=0;r<D;r++){
		for(int i=0;i*D+r<K;i++){
			nxt[i*D+r][0]=c++;
		}
	}
	setNxt();
//	for(int i=0;i<K;i++) printf("%d ",nxt[i][0]);
//	printf("\n");
	for(int i=0;i<N;i++) to[i]=get(i);
//	printf("to=");
//	for(int i=0;i<N;i++) printf("%d ",to[i]);
//	printf("\n");
//	ans=str;
	for(int i=0;i<N;i++){
		ans[to[i]]=str[i];
	}
}

int main(){
//	cin>>str;
	scanf("%s",str);
	int M;
//	cin>>M;
	scanf("%d",&M);
	N=strlen(str);
	int tmp=1;
	LOGN=1;
	ans[N]='\0';
	while(LOGN<21&&tmp<N){
		tmp*=2;
		LOGN++;
	}
	for(int q=0;q<M;q++){
	//	cin>>K>>D;
		scanf("%d%d",&K,&D);
		solve();
	//	cout<<ans<<"\n";
		printf("%s\n",ans);
		for(int i=0;i<N;i++) str[i]=ans[i];
	}
	return 0;
}