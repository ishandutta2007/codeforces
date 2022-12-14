#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int a[1010][1010];
int N,M;

long long rsum[1010],csum[1010];
long long row[1010],col[1010];

int K,p;

priority_queue<long long> que;

long long t[1100100];
long long tsum[1100100];

int main(){
	scanf("%d%d",&N,&M);
	scanf("%d%d",&K,&p);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<N;i++){
		rsum[i]=0;
		for(int j=0;j<M;j++) rsum[i]+=a[i][j];
	}
	for(int i=0;i<M;i++){
		csum[i]=0;
		for(int j=0;j<N;j++) csum[i]+=a[j][i];
	}
	for(int i=0;i<N;i++) que.push(rsum[i]);
	for(int i=1;i<=K;i++){
		long long x=que.top();
		que.pop();
		t[i]=x;
		que.push(x-p*M);
	}
	tsum[0]=0;
	for(int i=1;i<=K;i++) tsum[i]=tsum[i-1]+t[i];
	long long ans=-1ll<<60;
//	que.clear();
	while(!que.empty()) que.pop();
	for(int i=0;i<M;i++) que.push(csum[i]);
	long long y=0;
	for(int i=0;i<=K;i++){
		long long tmp=tsum[K-i]-(long long)i*(K-i)*p;
		tmp+=y;
		ans=max(ans,tmp);
		long long x=que.top();
		que.pop();
		y+=x;
		que.push(x-p*N);
	}
	cout<<ans<<"\n";
	return 0;
}