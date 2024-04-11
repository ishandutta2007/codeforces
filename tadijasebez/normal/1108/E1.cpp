#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=2*N;
int ls[M],rs[M],tsz,root,mx[M],lzy[M];
void Add(int &c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
vector<int> in[N],out[N];
int l[N],r[N],a[N];
int main()
{
	int n,i,m;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Add(root,1,n,i,i,a[i]);
	for(i=1;i<=m;i++) scanf("%i %i",&l[i],&r[i]),in[l[i]].pb(i),out[r[i]].pb(i);
	int ans=0,pos=1,cnt=0;
	for(i=1;i<=n;i++)
	{
		cnt+=in[i].size();
		for(int id:in[i]) Add(root,1,n,l[id],r[id],-1);
		int dif=mx[root]-(a[i]-cnt);
		if(ans<dif) ans=dif,pos=i;
		for(int id:out[i]) Add(root,1,n,l[id],r[id],1);
		cnt-=out[i].size();
	}
	printf("%i\n",ans);
	vector<int> my;
	for(int i=1;i<=m;i++) if(l[i]<=pos && r[i]>=pos) my.pb(i);
	printf("%i\n",my.size());
	for(int id:my) printf("%i ",id);
	return 0;
}