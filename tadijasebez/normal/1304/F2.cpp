#include <bits/stdc++.h>
using namespace std;
const int K=55;
const int N=20050;
const int M=2*N;
int root,ls[M],rs[M],tsz,mx[M],lzy[M];
void Build(int &c,int ss,int se,int a[]){
	c=++tsz;lzy[c]=0;
	if(ss==se){mx[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid,a);
	Build(rs[c],mid+1,se,a);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
int a[K][N],pre[N],dp[N];
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int j=1;j<=n;j++)for(int i=1;i<=m;i++)scanf("%i",&a[j][i]);
	for(int i=1;i<=m;i++)pre[i]=pre[i-1]+a[1][i]+a[2][i];
	for(int i=1;i<=m-k+1;i++)dp[i]=pre[i+k-1]-pre[i-1];
	for(int j=2;j<=n;j++){
		tsz=0;Build(root,1,m-k+1,dp);
		for(int i=1;i<=m;i++)pre[i]=pre[i-1]+a[j][i]+a[j+1][i];
		function<void(int)> Add=[&](int i){::Add(root,1,m-k+1,i-k+1,i,-a[j][i]);};
		function<void(int)> Del=[&](int i){::Add(root,1,m-k+1,i-k+1,i,a[j][i]);};
		for(int i=1;i<k;i++)Add(i);
		for(int i=k;i<=m;i++){
			Add(i);
			dp[i-k+1]=mx[root]+pre[i]-pre[i-k];
			Del(i-k+1);
		}
	}
	int ans=0;
	for(int i=1;i<=m-k+1;i++)ans=max(ans,dp[i]);
	printf("%i\n",ans);
	return 0;
}