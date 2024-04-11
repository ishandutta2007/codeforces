#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
struct Node
{
	int x,y;
};
Node a[N];
int n;
bool cmp(Node x,Node y)
{
	return x.x<y.x;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].x=read();
	for(int i=1;i<=n;i++) a[i].y=read();
	sort(a+1,a+n+1,cmp);
	priority_queue<int> q;
	int cur=0,cnt=0,ans=0,tmp=0;
	while(!q.empty()||cur<n)
	{
		cnt++;
		if(q.empty())
		{
			cnt=a[cur+1].x;
			while(cnt==a[cur+1].x&&cur<n)
			{
				cur++;
				tmp+=a[cur].y;
				q.push(a[cur].y);
			}
		}
		else
		{
			while(cnt==a[cur+1].x&&cur<n)
			{
				cur++;
				tmp+=a[cur].y;
				q.push(a[cur].y);
			}
		}
		tmp-=q.top(); q.pop();
		ans+=tmp;
	}
	cout<<ans<<endl;
	return 0;
}