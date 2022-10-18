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
#define N 20005
char s[N];
int n,ans,vis[N*2];
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		int len=-1,lim=i-2;
		for(int j=i;j+1<=n;j+=2)
		{
			if(s[j]=='R'&&s[j+1]=='L') ans++,lim=j+1;
			else
			{
				if(s[j]=='L'||s[j]=='U') len=-1;
				else
				{
					int nxt=-1;
					for(int k=j;k<=n;k++) if(s[k]=='U') {nxt=k; break;}
					if(nxt==-1) len=-1;
					else if(s[j]=='R') len=nxt-j;
					else
					{
						int t=j;
						while(s[t+1]=='L') t++;
						len=nxt-t;
					}
				}
				break;
			}
		}
		if(len==-1) continue;
		memset(vis,0,sizeof(vis));
		int ok=1;
		auto ins=[&](int x,int y)
		{
			if(y<1||y>len) ok=0;
			if(x<1) ok=0;
			if(vis[(x-1)*len+y]) ok=0;
			vis[(x-1)*len+y]=1;
		};
		for(int j=i,r=1;j+len-1<=n;j+=len,r++)
		{
			int fl=0;
			for(int k=1;k<=len;k++)
			{
				if(s[j+k-1]=='D') fl=1;
				if(s[j+k-1]=='U') ins(r-1,k);
				if(s[j+k-1]=='D') ins(r+1,k);
				if(s[j+k-1]=='L') ins(r,k-1);
				if(s[j+k-1]=='R') ins(r,k+1);
			}
			if(j+len-1>lim&&!fl&&ok) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}