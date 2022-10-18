#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1000005
int n,m,ans=inf;
int a[1005][1005],qcnt=0;
map<pii,int> vis;
int query(int x,int y,int op=0)
{
	if(x<0) exit(0);
	if(x>=n) exit(1);
	if(y<0) exit(2);
	if(y>=m) exit(op);
	if(vis[{x,y}]) return vis[{x,y}];
	qcnt++;
	if(qcnt>4*(n+m)) exit(0);
	printf("? %d %d\n",x+1,y+1); fflush(stdout);
#ifdef __LOCAL__
	int r=a[x+1][y+1];
#else
	int r=read();
#endif
	ans=min(ans,r);
	return vis[{x,y}]=r;
}
vector<int> solve(vector<int> r,vector<int> c)
{
//	print(r),print(c);
//	cout<<"--------------\n";
	if((int)r.size()<=2)
	{
		vector<int> ans(r.size());
		for(int i=0;i<(int)r.size();i++)
		{
			int mn=inf,mnpos=0;
			for(int j=0;j<(int)c.size();j++)
			{
				int t=query(r[i],c[j]);
				if(t<mn) mn=t,mnpos=c[j];
			}
			ans[i]=mnpos;
		}
		return ans;
	}
	vector<int> tmp;
	if(r.size()<c.size())
	{
		int siz=0;
		for(int i=0;i<(int)c.size();i++)
		{
			while(!tmp.empty())
			{
				if(tmp.back()>m) exit(5);
				if(c[i]>m) exit(6);
				int A=query(r[(int)tmp.size()-1],tmp.back(),10),B=query(r[(int)tmp.size()-1],c[i],11);
				if(A>B) tmp.pop_back();
				else break;
			}
			if(tmp.size()<r.size()) tmp.pb(c[i]);
		}
//		print(r),print(c),print(tmp);
//		printf("----------\n");
		c=tmp;
	}
	tmp.clear();
	for(int i=0;i<(int)r.size();i+=2) tmp.pb(r[i]);
	vector<int> pre=solve(tmp,c); pre.pb(c.back());
	vector<int> ans(r.size());
	for(int i=0;i<(int)r.size();i++)
	{
		if(i%2==0) ans[i]=pre[i/2];
		else
		{
			int L=lower_bound(c.begin(),c.end(),pre[i/2])-c.begin(),R=lower_bound(c.begin(),c.end(),pre[i/2+1])-c.begin(),mn=inf,mnpos=0;
//			printf("$ %d %d\n",L,R);
			for(int j=L;j<=R;j++)
			{
				int t=query(r[i],c[j],13);
				if(t<mn) mn=t,mnpos=c[j];
			}
			ans[i]=mnpos;
		}
	}
//	print(r),print(c);
//	cout<<"--------------\n";
//	printf("$ "),print(ans);
	return ans;
}
signed main()
{
	n=read(),m=read();
#ifdef __LOCAL__
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
#endif
	vector<int> r(n),c(m);
	for(int i=0;i<n;i++) r[i]=i;
	for(int i=0;i<m;i++) c[i]=i;
	solve(r,c);
	printf("! %d\n",ans);
	return 0;
}