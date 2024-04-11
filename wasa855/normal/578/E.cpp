#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
char str[N];
set<int> s[2];
signed main()
{
	scanf("%s",str+1); int n=strlen(str+1);
	int c0=0,c1=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='L') s[0].insert(i),c0++;
		else s[1].insert(i),c1++;
	}
	int sum=0,cur=0;
	vector<int> ans;
	while((int)ans.size()<n)
	{
		// cout<<"** "<<sum<<endl;
		// for(int i:ans) printf("%d ",i); cout<<"\n";
		sum++;
		if(s[1].empty()) {ans.pb(*s[0].begin()),s[0].erase(s[0].begin()); continue;}
		if(s[0].empty()) {ans.pb(*s[1].begin()),s[1].erase(s[1].begin()); continue;}
		int now=*s[1].begin()<*s[0].begin();
		if(sum==1)
		{
			if(n&1)
			{
				if(c0==n/2) now=1;
				else now=0;
			}
			cur=now^1;
		}
		if(now==cur)
		{
			int las=ans.back();
			if(str[las]=='R') s[1].insert(las);
			else s[0].insert(las);
			ans.pop_back();
			cur^=1;
		}
		int pl=*s[now].begin();
		while(1)
		{
			// printf("%d\n",pl);
			ans.pb(pl); s[now].erase(pl);
			now^=1;
			if(s[now].upper_bound(pl)==s[now].end()) break;
			else pl=*s[now].upper_bound(pl);
		}
		cur=now^1;
	}
	cout<<sum-1<<endl;
	for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
	return 0;
}