#include <bits/stdc++.h>
using namespace std;
const int N=100500;
const int S=317;
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int k,all,val[N],dp[N],q[2][S];
struct Block
{
	int srt[S],lzy,pre[S+1],zyb[S+1],sz,ptr;
	Block(){ sz=1;zyb[0]=-mod;zyb[1]=pre[0]=pre[1]=lzy=0;ptr=1;}
	void upd(int qs, int qe, int f)
	{
		all=sub(all,pre[ptr]);
		int i,j,l,lsz=0,rsz=0;
		for(i=0;i<S;i++)
		{
			val[srt[i]]+=lzy;
			if(qs<=srt[i] && qe>=srt[i])
			{
				val[srt[i]]+=f;
				q[0][lsz++]=srt[i];
			}
			else q[1][rsz++]=srt[i];
		}
		for(i=j=l=0;i<lsz || j<rsz;)
		{
			if(i>=lsz) srt[l++]=q[1][j++];
			else if(j>=rsz) srt[l++]=q[0][i++];
			else if(val[q[0][i]]<val[q[1][j]]) srt[l++]=q[0][i++];
			else srt[l++]=q[1][j++];
		}
		for(i=ptr=sz=0;i<S;i++)
		{
			if(i==0 || val[srt[i]]!=val[srt[i-1]]) sz++,pre[sz]=pre[sz-1],zyb[sz]=val[srt[i]];
			pre[sz]=add(pre[sz],dp[srt[i]]);
			if(zyb[sz]<=k) ptr=sz;
		}
		lzy=0;
		all=add(all,pre[ptr]);
	}
	void upd(int f)
	{
		lzy+=f;
		all=sub(all,pre[ptr]);
		if(zyb[ptr]+lzy>k) ptr--;
		if(ptr<sz && zyb[ptr+1]+lzy<=k) ptr++;
		all=add(all,pre[ptr]);
	}
} blk[S];
int fir[N],sec[N],a[N];
void solve(int l, int r, int f)
{
	if(l>r) return;
	int L=l/S,R=r/S,i;
	blk[L].upd(l,r,f);
	if(L==R) return;
	blk[R].upd(l,r,f);
	for(i=L+1;i<R;i++) blk[i].upd(f);
}
int main()
{
	int n,i,j;
	scanf("%i %i",&n,&k);
	dp[0]=1;
	for(i=0;i<S;i++) for(j=0;j<S;j++) blk[i].srt[j]=i*S+j;
	blk[0].upd(0,-1,0);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		solve(sec[a[i]],fir[a[i]]-1,-1);
		solve(fir[a[i]],i-1,1);
		sec[a[i]]=fir[a[i]];
		fir[a[i]]=i;
		dp[i]=all;
		blk[i/S].upd(0,-1,0);
	}
	printf("%i\n",dp[n]);
	return 0;
}