#include <bits/stdc++.h>
using namespace std;
const int N=400050;
const int L=20;
int a[N],rmq[L][N],n,logs[N];
void BuildSparseTable(int n)
{
	for(int i=2;i<=n;i++) logs[i]=logs[i>>1]+1;
	for(int i=1;i<=n;i++) rmq[0][i]=a[i];
	for(int j=1;j<L;j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++) rmq[j][i]=min(rmq[j-1][i],rmq[j-1][i+(1<<(j-1))]);
	}
}
int RMQ(int l, int r)
{
	int k=logs[r-l+1];
	return min(rmq[k][l],rmq[k][r-(1<<k)+1]);
}
int GetR(int l, int r)
{
	int top=r,bot=l,mid,ans=r+1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(RMQ(l,mid)<a[l]) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	return ans;
}
int GetL(int l, int r)
{
	int top=r,bot=l,mid,ans=l-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(RMQ(mid,r)<a[r]) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	return ans;
}
const int M=N*2;
const int inf=1e9+7;
struct SegmentTree
{
	int ls[M],rs[M],tsz,root,mx[M],lzy[M],sz;
	SegmentTree(){}
	void Set_sz(int _sz){ sz=_sz;}
	void Set(int &c, int ss, int se, int qs, int qe, int f)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(!c) c=++tsz;
		if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]+=f;return;}
		int mid=ss+se>>1;
		Set(ls[c],ss,mid,qs,qe,f);
		Set(rs[c],mid+1,se,qs,qe,f);
		mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
	}
	int Get(int c, int ss, int se, int qs, int qe)
	{
		if(qs>qe || qs>se || ss>qe) return -inf;
		if(qs<=ss && qe>=se) return mx[c];
		int mid=ss+se>>1;
		return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
	}
	int Get(int qs, int qe){ return Get(root,1,sz,qs,qe);}
	void Set(int qs, int qe, int f)
	{
		//printf("%i %i %i\n",qs,qe,f);
		Set(root,1,sz,qs,qe,f);
	}
} ST;
int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),a[i+n]=a[i];
	BuildSparseTable(n*2);
	ST.Set_sz(n*2);
	for(int i=1;i<=n;i++)
	{
		ST.Set(GetL(1,i)+1,i,1);
		ST.Set(i,GetR(i,n*2)-1,1);
	}
	pair<int,int> ans={inf,-1};
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			ST.Set(i,GetR(i,n*2)-1,-1);
			ST.Set(GetL(1,i)+1,i,-1);
			ST.Set(GetL(1,i+n)+1,i+n,1);
			ST.Set(i+n,GetR(i+n,n*2)-1,1);
		}
		ans=min(ans,{ST.Get(1+i,n+i),i});
		//printf("cyc sh:%i %i\n",i,ST.Get(1+i,n+i));
		//for(int j=1;j<=n;j++) printf("%i ",ST.Get(i+j,i+j));printf("\n");
	}
	printf("%i %i\n",ans.first-1,ans.second);
	return 0;
}