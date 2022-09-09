#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
const int N=200050;
const int M=N*2;
const ll inf=9e18;
int x[M],ls[M],rs[M],clock,root;
ll sum[M];
void Set(int &c, int ss, int se, int qi, int val, int f)
{
	if(!c) c=++clock;
	x[c]+=f;sum[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val,f);
	else Set(rs[c],mid+1,se,qi,val,f);
}
int A;
ll Get(int c, int ss, int se, int k)
{
	if(ss==se)
	{
		A=ss;
		if(x[c]>k) return 0;
		return sum[c];
	}
	int mid=ss+se>>1;
	if(x[ls[c]]<k) return sum[ls[c]]+Get(rs[c],mid+1,se,k-x[ls[c]]);
	else return Get(ls[c],ss,mid,k);
}
vector<int> all;
void PrintActive(int c, int ss, int se)
{
	if(ss==se)
	{
		if(x[c]) printf("%i ",all[ss-1]);
		return;
	}
	int mid=ss+se>>1;
	PrintActive(ls[c],ss,mid);
	PrintActive(rs[c],mid+1,se);
}
vector<int> Only1,Only2,Both;
int id[N],c[N];
bool was1[N],was2[N];
ll dp1[N],dp2[N];
bool comp(int a, int b){ return c[a]<c[b];}
int main()
{
	int n,m,k,i,a,b,x;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&c[i]),all.pb(i);
	sort(all.begin(),all.end(),comp);
	for(i=0;i<all.size();i++) id[all[i]]=i+1;
	scanf("%i",&a);while(a--) scanf("%i",&x),was1[x]=1;
	scanf("%i",&b);while(b--) scanf("%i",&x),was2[x]=1;
	for(i=0;i<n;i++)
	{
		if(was1[all[i]] && was2[all[i]]) Both.pb(all[i]);
		else if(was1[all[i]]) Only1.pb(all[i]);
		else if(was2[all[i]]) Only2.pb(all[i]);
		else Set(root,1,N,i+1,c[all[i]],1);
	}
	while(Only2.size()>Only1.size()) Set(root,1,N,id[Only2.back()],c[Only2.back()],1),Only2.pop_back();
	while(Only1.size()>Only2.size()) Set(root,1,N,id[Only1.back()],c[Only1.back()],1),Only1.pop_back();
	for(i=0;i<Both.size();i++) dp1[i+1]=dp1[i]+c[Both[i]];
	for(i=0;i<Only1.size();i++) dp2[i+1]=dp2[i]+c[Only1[i]]+c[Only2[i]];
	ll sol=inf,ans;
	int last1=Both.size();
	int last2=Only1.size();
	for(i=0;i<=Both.size();i++)
	{
		int j=k-i;
		if(j>Only1.size()) continue;
		int l=m-i-2*j;
		if(l<0) continue;
		while(last1>i)
		{
			//printf("%i Add\n",Both[last1-1]);
			Set(root,1,N,id[Both[last1-1]],c[Both[last1-1]],1);
			last1--;
		}
		while(last1<i)
		{
			//printf("%i Err\n",Both[last1]);
			Set(root,1,N,id[Both[last1]],-c[Both[last1]],-1);
			last1++;
		}
		while(last2>j)
		{
			//printf("%i %i Add\n",Only1[last2-1],Only2[last2-1]);
			Set(root,1,N,id[Only1[last2-1]],c[Only1[last2-1]],1);
			Set(root,1,N,id[Only2[last2-1]],c[Only2[last2-1]],1);
			last2--;
		}
		while(last2<j)
		{
			//printf("%i %i Err\n",Only1[last2],Only2[last2]);
			Set(root,1,N,id[Only1[last2]],-c[Only1[last2]],-1);
			Set(root,1,N,id[Only2[last2]],-c[Only2[last2]],-1);
			last2++;
		}
		ans=dp1[i]+dp2[j]+Get(root,1,N,l);
		//printf("i:%i j:%i l:%i ans:%lld dp1:%lld dp2:%lld get:%lld ss:%i Active: ",i,j,l,ans,dp1[i],dp2[j],Get(root,1,N,l),A);
		//PrintActive(root,1,N);printf("\n");
		if(sol>ans) sol=ans;
	}
	if(sol==inf) printf("-1\n");
	else printf("%lld\n",sol);
	return 0;
}