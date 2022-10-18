#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
struct Node
{
	int x,y,id;
};
Node a[N*4],b[N*2];
int n,m,cnt,tot;
priority_queue<pii> q;
bool del[N];
bool cmp(Node x,Node y)
{
	return x.x<y.x;
}
void add(int x,int y)
{
	while(!q.empty())
	{
		if(del[q.top().sec]) q.pop();
		else break;
	}
	if(q.empty()) return ;
	int u=-q.top().fir;
	a[++tot]=(Node){u-y,y-u,1};
	a[++tot]=(Node){u-x,u-x,-1};
}
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),t=read();
		b[++cnt]=(Node){x,t,i};
		b[++cnt]=(Node){y,t,-i};
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(i>1&&b[i].x>b[i-1].x) add(b[i-1].x,b[i].x);
		if(b[i].id>0) q.push(mp(-b[i].y,b[i].id));
		else del[-b[i].id]=1;
	}
	sort(a+1,a+tot+1,cmp);
	int i=1;
	int R=0,S=0;
	while(m--)
	{
		int x=read();
		while(i<=tot&&a[i].x<=x)
		{
			S+=a[i].y,R+=a[i].id;
			i++;
		}
		printf("%d\n",x*R+S);
	}
	return 0;
}