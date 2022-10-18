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
char s[N],a[N];
int n,p[N];
void work()
{
	n=read();
	scanf("%s",s+1);
	a[0]='$';
	for(int i=1;i<=n;i++) a[i*2-1]=s[i],a[i*2]='*';
	a[n*2+1]='#';
	p[0]=p[1]=1;
	int id=0;
	for(int j=2;j<=n*2;j++)
	{
		if(p[id]+id>j) p[j]=min(p[id*2-j],p[id]+id-j);
		else p[j]=1;
		while(a[j-p[j]]==a[j+p[j]]) p[j]++;
		if(p[id]+id<p[j]+j) id=j;
	}
	// for(int i=1;i<=n*2;i++) printf("%c%c",a[i]," \n"[i==n*2]);
	// for(int i=1;i<=n*2;i++) printf("%d%c",p[i]," \n"[i==n*2]);
	// cout<<s[1]<<endl;
	int cur=1,ans=0;
	while(cur<n)
	{
		if(s[cur]=='(') cur+=2,ans++;
		else
		{
			int fl=0;
			for(int j=cur+1;j<=n;j++)
			{
				int mxl=p[j+cur-1];
				// printf("%d %d - %d\n",cur,j,mxl);
				if(mxl>=j-cur+1)
				{
					cur=j+1,ans++;
					fl=1;
					break;
				}
			}
			if(!fl) break;
		}
	}
	printf("%d %d\n",ans,n-cur+1);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}