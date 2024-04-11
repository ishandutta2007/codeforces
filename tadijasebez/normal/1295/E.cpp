#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll mn[M],lzy[M];
void Add(int &c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz;
	if(qs<=ss && qe>=se){mn[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
}
int p[N],a[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++)Add(root,0,n,p[i],n,a[i]);
	ll ans=9e18;
	for(int i=1;i<n;i++){
		Add(root,0,n,p[i],n,-a[i]);
		Add(root,0,n,0,p[i]-1,a[i]);
		ans=min(ans,mn[root]);
	}
	printf("%lld\n",ans);
	return 0;
}