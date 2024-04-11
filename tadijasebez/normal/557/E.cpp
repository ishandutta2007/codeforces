#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=5050;
const int M=N*2500;
char s[N];
bool dp[N][N];
bool was[N][N];
bool Check(int l, int r)
{
	if(was[l][r]) return dp[l][r];
	was[l][r]=1;
	if(r-l<4) return dp[l][r]=(s[l]==s[r]);
	return dp[l][r]=(s[l]==s[r]&&Check(l+2,r-2));
}
int tot;
//int id[N],tot,sa[N];
/*pair<pair<int,int> ,int>  tmp[N];
void BuildSuffixArray()
{
	s[++tot]='a'+26;
	int i,j;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a';
	for(j=0;j<20;j++)
	{
		for(i=1;i<=tot;i++) tmp[i]=mp(mp(id[i],id[i+(1<<j)]),i);
		sort(tmp+1,tmp+1+tot);
		int c=0;
		for(i=1;i<=tot;i++)
		{
			id[tmp[i].second]=c+1;
			c+=(tmp[i].first!=tmp[i+1].first);
		}
		if(c==tot) break;
	}
	for(i=1;i<=tot;i++) sa[id[i]]=i;
}
int lcp[N];
void BuildLCPArray()
{
	int k=0,i;
	for(i=1;i<=tot;i++)
	{
		if(sa[i]==tot) k=0;
		else
		{
			int j=sa[id[i]+1];
			while(i+k<=tot && j+k<=tot && s[i+k]==s[j+k]) k++;
			lcp[id[i]]=k;
			if(k>0) k--;
		}
	}
}
int rmq[N][17],logs[N];
int min(int a, int b){ return a>b?b:a;}
void Preprocess(){ for(int i=2;i<N;i++) logs[i]=logs[i>>1]+1;}
void BuildSparseTable()
{
	int i,j;
	for(i=1;i<=tot;i++) rmq[i][0]=lcp[i];
	for(j=1;j<17;j++)
	{
		if(tot-(1<<j)<0) break;
		for(i=1;i<=tot-(1<<j)+1;i++)
		{
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
		}
	}
}
void Swap(int &a, int &b){ a^=b,b^=a,a^=b;}
int LCP(int l, int r)
{
	l=id[l];
	r=id[r];
	if(l>r) Swap(l,r);
	if(l==r) return tot;
	r--;
	int k=logs[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
bool comp(pair<int,int> a, pair<int,int> b)
{
	int len=LCP(a.first,b.first);
	len=min(len,a.second-a.first+1);
	len=min(len,b.second-b.first+1);
	if(len==b.second-b.first+1) return 0;
	if(len==a.second-a.first+1) return 1;
	return s[a.first+len]<s[b.first+len];
}*/
vector<int> sol;
int go[M][2],tsz,root;
vector<int> ids[M];
void Insert(int &c, int l, int r)
{
	if(!c) c=++tsz;
	if(dp[l][r-1]) ids[c].pb(l*N+r-1);
	if(r==tot) return;
	Insert(go[c][s[r]-'a'],l,r+1);
}
/*void BuildTrie(int c)
{
	if(!c) return;
	BuildTrie(go[c][0]);
	BuildTrie(go[c][1]);
	sum[c]+=sum[go[c][0]];
	sum[c]+=sum[go[c][1]];
}*/
/*pair<int,int> Find(int c, int k)
{
	if(!go[c][0] && !go[c][1]) return ids[c][k-1];
	if(sum[go[c][0]]>=k) return Find(go[c][0],k);
	else return Find(go[c][1],k-sum[go[c][0]]);
}*/
void Take(int c)
{
	if(!c) return;
	for(int i=0;i<ids[c].size();i++) sol.pb(ids[c][i]);
	Take(go[c][0]);
	Take(go[c][1]);
}
/*void Print(int c)
{
	if(!c) return;
	for(int i=0;i<ids[c].size();i++) printf("%i %i\n",ids[c][i].first,ids[c][i].second);
	Print(go[c][0]);
	Print(go[c][1]);
}*/
int main()
{
	scanf("%s",s+1);
	tot=strlen(s+1);
	int i,j;
	for(i=1;i<=tot;i++) for(j=tot;j>=i;j--)
	{
		if(!was[i][j]) Check(i,j);
		//if(dp[i][j]) sol.pb(mp(i,j));
	}
	tot++;
	for(i=1;i<tot;i++) Insert(root,i,i);
	//BuildTrie(root);
	Take(root);
	//Print(root);
	//BuildSuffixArray();
	//BuildLCPArray();
	//Preprocess();
	//BuildSparseTable();
	//sort(sol.begin(),sol.end(),comp);
	int k;scanf("%i",&k);k--;
	//if(k>=sol.size()) return printf("???\n"),0;
	//int l=sol[k].first,r=sol[k].second;
	//pair<int,int> ans=Find(root,k);
	int l=sol[k]/N,r=sol[k]%N;
	for(i=l;i<=r;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
}