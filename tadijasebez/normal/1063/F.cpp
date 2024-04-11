#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=500050;
const int L=19;
int go[N],tsz,fir[N];
pair<int,int> f[N];
void Ins(int x, pair<int,int> y){ tsz++;go[tsz]=fir[x];f[tsz]=y;fir[x]=tsz;}
char s[N];
int tot,sa[N],id[N],lcp[N],rmq[N][L],logs[N];
bool comp(int i, int j){ return s[i]<s[j];}
void BuildSuffixArray()
{
	int i,j,k;
      s[++tot]='a'+26;
      for(i=1;i<=tot;i++) sa[i]=i,id[i]=s[i]-'a'+1;
      sort(sa+1,sa+1+tot,comp);
	for(j=0;j<20;j++)
	{
		for(i=1;i<=tot;i++) if(sa[i]+(1<<j)>tot) Ins(id[sa[i]],mp(0,sa[i]));
		for(i=tot;i>=1;i--) if(sa[i]-(1<<j)>0) Ins(id[sa[i]-(1<<j)],mp(id[sa[i]],sa[i]-(1<<j)));
		pair<int,int> last;
		int c=0,sz=0;
		for(i=1;i<=max(tot,27);i++)
		{
			for(k=fir[i];k;k=go[k])
			{
				pair<int,int> tmp=mp(i,f[k].first);
				c+=tmp!=last;last=tmp;
				id[f[k].second]=c;
				sa[++sz]=f[k].second;
			}
			fir[i]=0;
		}
            tsz=0;
		if(c==tot) return;
	}
}
void BuildLCPArray()
{
	int i,j,k=0;
	for(i=1;i<=tot;i++) if(id[i]!=tot)
	{
		j=sa[id[i]+1];
		while(max(i,j)+k<=tot && s[i+k]==s[j+k]) k++;
		lcp[id[i]]=k;
		if(k) k--;
	}
}
void BuildSparseTable()
{
	int i,j;
	for(i=2;i<=tot;i++) logs[i]=logs[i>>1]+1;
	for(i=1;i<=tot;i++) rmq[i][0]=lcp[i];
	for(j=1;j<L;j++) for(i=1;i<=tot-(1<<j)+1;i++) rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
}
int LCP(int l, int r)
{
	if(l==r) return tot-l;
	l=id[l];r=id[r];
	if(l>r) swap(l,r);
	r--;
	int k=logs[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
struct SegmentTree
{
	vector<int> mx;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n;mx.assign(n*2,0);}
	int Get(int l, int r)
	{
		int ans=0;
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans=max(mx[l],ans),l++;
			if(r%2==0) ans=max(mx[r],ans),r--;
		}
		return ans;
	}
	void Set(int i, int x){ i+=sz-1;mx[i]=x;for(i>>=1;i;i>>=1) mx[i]=max(mx[i<<1],mx[i<<1|1]);}
} ST;
int dp[N],ptr;
pair<int,int> FindRange(int i, int len)
{
	int top=tot,bot=id[i]+1,mid,r=id[i],l=id[i];
	while(top>=bot){ mid=top+bot>>1;if(LCP(i,sa[mid])>=len) r=mid,bot=mid+1;else top=mid-1;}
	top=id[i]-1,bot=1;
	while(top>=bot){ mid=top+bot>>1;if(LCP(i,sa[mid])>=len) l=mid,top=mid-1;else bot=mid+1;}
	return mp(l,r);
}
bool Check(int i, int len)
{
	while(ptr>i+len) ptr--,ST.Set(id[ptr],dp[ptr]);
	while(ptr<i+len) ST.Set(id[ptr],0),ptr++;
	int l,r,L,R;
	tie(l,r)=FindRange(i,len-1);
	tie(L,R)=FindRange(i+1,len-1);
	return max(ST.Get(l,r),ST.Get(L,R))>=len-1;
}
int main()
{
	int n,i;
	scanf("%i",&n);tot=n;
	scanf("%s",s+1);
	BuildSuffixArray();
	BuildLCPArray();
	BuildSparseTable();
	ST.init(tot);
	ptr=n+1;
	int ans=0;
	for(i=n;i>=1;i--)
	{
		dp[i]=dp[i+1]+1;
		while(dp[i]>1 && !Check(i,dp[i])) dp[i]--;
		ans=max(ans,dp[i]);
	}
	printf("%i\n",ans);
	return 0;
}