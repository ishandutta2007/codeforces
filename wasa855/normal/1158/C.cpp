#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 500005
struct Node
{
	int p,num;
};
Node a[N];
int ans[N];
bool cmp(Node x,Node y)
{
	if(x.p!=y.p) return x.p>y.p;
	return x.num<y.num;
}
void work()
{
	int n;
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x!=-1)
		{
			a[++m].p=x;
			a[m].num=i;
		}
	}
	stack<int> s;
	for(int i=1;i<=m;i++)
	{
		while(!s.empty()&&a[i].num>=s.top()) s.pop();
		if(!s.empty()&&a[i].p>s.top())
		{
			cout<<"-1\n";
			return ;
		}
		s.push(a[i].p);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) ans[i]=0;
	int res=n;
//	cout<<"**"<<n<<endl;
	for(int i=1;i<=m;i++)
	{
		if(a[i].p!=n+1&&ans[a[i].p]==0) ans[a[i].p]=res--;
		if(ans[a[i].num]==0) ans[a[i].num]=res--;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==0) ans[i]=res--;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	cout<<"\n";
}
signed main()
{
	int T;
	cin>>T;
	while(T--) work();
	return 0;
}