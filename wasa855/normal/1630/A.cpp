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
void work()
{
	int n=read(),k=read();
	if(k==0)
	{
		int ful=n-1;
		for(int i=0;i<n;i++)
		{
			int t=i^ful;
			if(i<t) printf("%d %d\n",i,t);
		}
	}
	else if(n!=k+1)
	{
		int ful=n-1;
		for(int i=1;i<n;i++)
		{
			int t=i^ful;
			if(i!=k&&t!=k&&i<t) printf("%d %d\n",i,t);
		}
		printf("%d %d\n",k,ful);
		printf("%d %d\n",0,ful^k);
	}
	else if(n==4) printf("-1\n");
	else
	{
		int ful=n-1;
		int A=1,B=ful^2;
		for(int i=2;i<n;i++)
		{
			int t=i^ful;
			if(i!=n-1&&t!=n-1&&i!=B&&t!=B&&i<t) printf("%d %d\n",i,t);
		}
		printf("%d %d\n",ful-1,ful);
		printf("%d %d\n",A,B);
		printf("%d %d\n",0,2);
		
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}