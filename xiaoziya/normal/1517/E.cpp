#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=200005,mod=998244353;
int T,n,ans;
int v[maxn],t[2][maxn];
long long all;
long long sum[maxn],summ[maxn];
struct node{
	int typ,pos;
	long long val;
}num[maxn*2];
inline int cmp(node a,node b){
	return a.val>b.val||(a.val==b.val&&a.typ>=b.typ);
}
void update(int x,int v,int p){
	for(int i=x;i<=n;i+=lowbit(i))
		t[p][i]+=v;
}
int query(int x,int p){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res=(res+t[p][i])%mod;
	return res;
}
int solve(vector<int>b,long long goal){
	int n=b.size(),res=0;
	sum[n+1]=0;
	for(int i=n;i>=1;i--)
		v[i]=b[i-1],sum[i]=sum[i+1]+v[i];
	summ[0]=summ[1]=0;
	for(int i=2;i<=n;i++)
		summ[i]=summ[i-2]+v[i];
	int nums=0;
	for(int i=1;i<=n;i++){
		if(i<n)
			num[++nums]=node{1,i,goal+summ[i-1]};
		if(i>1)
			num[++nums]=node{2,i,summ[i-2]+sum[i]};
	}
	sort(num+1,num+1+nums,cmp);
	for(int i=1;i<=nums;i++){
		if(num[i].typ==1)
			res=(res+query(n-num[i].pos+1,(num[i].pos&1)^1))%mod;
		if(num[i].typ==2)
			update(n-num[i].pos+1,1,num[i].pos&1);
	}
	for(int i=1;i<=nums;i++)
		if(num[i].typ==2)
			update(n-num[i].pos+1,-1,num[i].pos&1);
//	for(int i=1;i<n;i++)
//		for(int j=i+1;j<=n;j+=2)
//			if(summ[j-2]+sum[j]>=goal+summ[i-1])
//				res++;
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		all=0;
		scanf("%d",&n);
		vector<int>A,B,C,D;
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x),all+=x;
			A.push_back(x);
			if(i>1)
				B.push_back(x);
			if(i<n)
				C.push_back(x);
			if(i>1&&i<n)
				D.push_back(x);
		}
		ans=1;
		long long now=0;
		for(int i=0;i<n-1;i++){
			now+=A[i];
			if(now>all-now)
				ans++;
		}
		all=all/2+1;
		ans=(0ll+ans+solve(A,all)+solve(B,all-A[0])+solve(C,all)+solve(D,all-A[0]))%mod;
		printf("%d\n",ans);
	}
	return 0;
}