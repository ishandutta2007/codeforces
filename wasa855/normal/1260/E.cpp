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
#define N 400005
int a[N];
bool b[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=0;i<=18;i++) b[1<<i]=1;
	priority_queue<int,vector<int>,greater<int>> q;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==-1) break;
		q.push(a[i]);
		if(b[i]==1)
		{
			ans+=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}