#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		int x=floor(sqrt(d-1))-1,y=ceil(sqrt(d))+1;
		int maxn=n+5;
		for(int i=max(x,0LL);i<=y;i++)
		{
			if(i+(d+i)/(i+1)<maxn) maxn=i+(d+i)/(i+1);
		}
		printf("%s\n",maxn<=n?"YES":"NO");
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}