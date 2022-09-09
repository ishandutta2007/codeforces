#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=2*N;
const int H=17*N;
const int inf=1e9+7;
struct SegmentTreeSum
{
	int sum[M];
	SegmentTreeSum(){}
	void init(){ for(int i=0;i<M;i++) sum[i]=0;}
	void Set(int i, int f){ for(i+=N;i;i>>=1) sum[i]+=f;}
	int Get(int l, int r)
	{
		int ret=0;
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
            if(l%2==1) ret+=sum[l++];
            if(r%2==0) ret+=sum[r--];
		}
		return ret;
	}
} ST;
struct SegmentTreeMax
{
	int mx[M];
	void init(){ for(int i=0;i<M;i++) mx[i]=-inf;}
	SegmentTreeMax(){ init();}
	void Set(int i, int f){ i+=N;mx[i]=f;for(i>>=1;i;i>>=1) mx[i]=max(mx[i<<1],mx[i<<1|1]);}
	int Get(int l, int r)
	{
		int ret=-inf;
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
            if(l%2==1) ret=max(ret,mx[l]),l++;
            if(r%2==0) ret=max(ret,mx[r]),r--;
		}
		return ret;
	}
};
struct SegmentTreeMin
{
	int mn[M];
	void init(){ for(int i=0;i<M;i++) mn[i]=inf;}
	SegmentTreeMin(){ init();}
	void Set(int i, int f){ i+=N;mn[i]=f;for(i>>=1;i;i>>=1) mn[i]=min(mn[i<<1],mn[i<<1|1]);}
	int Get(int l, int r)
	{
		int ret=inf;
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
            if(l%2==1) ret=min(ret,mn[l]),l++;
            if(r%2==0) ret=min(ret,mn[r]),r--;
		}
		return ret;
	}
};
struct SegmentTreeRangeAdd
{
	int sum[M];
	void init(){ for(int i=0;i<M;i++) sum[i]=0;}
	SegmentTreeRangeAdd(){ init();}
	int Get(int i){ int ret=0;for(i+=N;i;i>>=1) ret+=sum[i];return ret;}
	void Set(int l, int r, int f)
	{
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
            if(l%2==1) sum[l]+=f,l++;
            if(r%2==0) sum[r]+=f,r--;
		}
	}
} RT;
int ls[H],rs[H],mn[H],mx[H],tsz,root[N];
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++tsz;
	if(ss==se){ mn[c]=mx[c]=f;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]]);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
int MX(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return -inf;
	if(qs<=ss && qe>=se) return mx[c];
	int mid=ss+se>>1;
	return max(MX(ls[c],ss,mid,qs,qe),MX(rs[c],mid+1,se,qs,qe));
}
int MN(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return inf;
	if(qs<=ss && qe>=se) return mn[c];
	int mid=ss+se>>1;
	return min(MN(ls[c],ss,mid,qs,qe),MN(rs[c],mid+1,se,qs,qe));
}
int l[N],r[N],a[N],lst[N],ans[N],rng[N];
vector<int> Qs[N];
int main()
{
	mx[0]=-inf;mn[0]=inf;
	int n,q,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i %i",&l[i],&r[i]),Qs[r[i]].pb(i);
	for(i=1;i<=n;i++)
	{
		if(lst[a[i]]) ST.Set(lst[a[i]],-1);
		ST.Set(i,1);lst[a[i]]=i;
		for(int j:Qs[i]) ans[j]=ST.Get(l[j],r[j]);
	}
	for(i=0;i<N;i++) lst[i]=0;
	for(i=1;i<=n;i++)
	{
		if(lst[a[i]])
		{
			RT.Set(rng[lst[a[i]]],lst[a[i]],-1);
			Set(root[a[i]],1,n,lst[a[i]],i-lst[a[i]]);
			//MN.Set(lst[a[i]],i-lst[a[i]]);
			//MX.Set(lst[a[i]],i-lst[a[i]]);
		}
		lst[a[i]]=i;
		int top=i,bot=1,mid;
		while(top>=bot)
		{
			mid=top+bot>>1;
			int mx=MX(root[a[i]],1,n,mid,i);//MX.Get(mid,i);
			int mn=MN(root[a[i]],1,n,mid,i);//MN.Get(mid,i);
			if(mn==inf || mn==mx) rng[i]=mid,top=mid-1;
			else bot=mid+1;
		}
		//printf("%i ",rng[i]);
		RT.Set(rng[i],i,1);
		for(int j:Qs[i]) if(RT.Get(l[j])>0) ans[j]--;
	}
	printf("\n");
	for(i=1;i<=q;i++) printf("%i\n",ans[i]+1);
	return 0;
}