#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
const int M=2*N;
int lid[N],rid[N],tid;
vector<int> E[N];
void DFS(int u)
{
	lid[u]=++tid;
	for(int v:E[u]) DFS(v);
	rid[u]=tid;
}
int ls[M],rs[M],tsz,root,mx[M],lzy[M];
void Set(int &c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ mx[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
int a[N],S[N],c;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>=1;i--)
	{
		while(c && a[S[c]]<=a[i]) c--;
		E[S[c]].push_back(i);
		S[++c]=i;
	}
	DFS(0);
	for(i=1;i<k;i++) Set(root,1,tid,lid[i],rid[i],1);
	for(i=k;i<=n;i++)
	{
		Set(root,1,tid,lid[i],rid[i],1);
		if(i>k) Set(root,1,tid,lid[i-k],rid[i-k],-1);
		printf("%i ",mx[root]);
	}
	return 0;
}