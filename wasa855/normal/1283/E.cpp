#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int cnt[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) cnt[read()]++;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i])
		{
			ans++;
			i+=2;
		}
	}
	cout<<ans<<" ";
	for(int i=0;i<=n;i++)
	{
		if(!cnt[i]&&cnt[i+1]) cnt[i+1]--,cnt[i]++;
		if(cnt[i]>1) cnt[i]--,cnt[i+1]++;
	}
	ans=0;
	for(int i=0;i<=n+1;i++)
	{
		if(cnt[i]) ans++;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}