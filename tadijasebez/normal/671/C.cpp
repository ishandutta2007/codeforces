#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=200050;
const int M=2*N;
const int inf=1e9+7;
int ls[M],rs[M],tsz,root,lzy[M],fir[M],sec[M],cnt[M];
ll sum[M];
void Upd(int c, int x)
{
	if(fir[c]>=x) return;
	sum[c]+=(ll)cnt[c]*(x-fir[c]);fir[c]=x;
	lzy[c]=x;
}
void Push(int c){ if(lzy[c]) Upd(ls[c],lzy[c]),Upd(rs[c],lzy[c]);lzy[c]=0;}
void Take(int c)
{
	fir[c]=min(fir[ls[c]],fir[rs[c]]);
	sum[c]=sum[ls[c]]+sum[rs[c]];
	if(fir[ls[c]]==fir[rs[c]]) sec[c]=min(sec[ls[c]],sec[rs[c]]),cnt[c]=cnt[ls[c]]+cnt[rs[c]];
	else if(fir[ls[c]]==fir[c]) sec[c]=min(sec[ls[c]],fir[rs[c]]),cnt[c]=cnt[ls[c]];
	else if(fir[rs[c]]==fir[c]) sec[c]=min(fir[ls[c]],sec[rs[c]]),cnt[c]=cnt[rs[c]];
}
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=0;fir[c]=0;sec[c]=inf;cnt[c]=se-ss+1;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || ss>qe || qs>se || fir[c]>=x) return;
	if(qs<=ss && qe>=se && sec[c]>x){ Upd(c,x);return;}
	Push(c);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
	Take(c);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	Push(c);
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int a[N],rid[N],lid[N];
int pre[N],suf[N];
vector<int> Div[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j) continue;
            Div[i].pb(j);
            if(j*j!=a[i]) Div[i].pb(a[i]/j);
		}
		for(j:Div[i]) rid[j]=i;
	}
	for(i=n;i>=1;i--) for(j:Div[i]) lid[j]=i;
	Build(root,1,n);
	ll sol=0;
	for(i=1;i<=n;i++){ pre[i]=pre[i-1];for(j:Div[i]) if(lid[j]<i) pre[i]=max(pre[i],j);}
	for(i=n;i>=1;i--){ suf[i]=suf[i+1];for(j:Div[i]) if(rid[j]>i) suf[i]=max(suf[i],j);}
	for(i=1;i<=n;i++) Set(root,1,n,i,i,suf[i]);
	sol=Get(root,1,n,2,n);
	for(i=1;i<n;i++)
	{
		//printf("i:%i pre:%i suf:%i\n",i,pre[i],suf[i]);
		for(j:Div[i]) if(rid[j]) Set(root,1,n,i+1,rid[j],j);
		int top=n,bot=i+2,id=n+1,mid;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(root,1,n,mid,mid)<pre[i]) id=mid,top=mid-1;
			else bot=mid+1;
		}
		//printf("id:%i\n",id);
		sol+=(ll)(n-id+2)*pre[i];
		//printf("sol:%lld ",sol);
		sol+=Get(root,1,n,i+2,id-1);
		//printf(" %lld\n",sol);
	}
	printf("%lld\n",sol);
	return 0;
}