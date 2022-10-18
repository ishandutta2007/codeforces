#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 300005
struct Node
{
	int bui,leng;
};
Node a[N];
bool cmp(Node x,Node y)
{
	if(x.bui!=y.bui) return x.bui>y.bui;
	return x.leng>y.leng;
}
int pre[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i].leng=read(),a[i].bui=read();
	}
	sort(a+1,a+n+1,cmp);
	priority_queue<int> q;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		q.push(-a[i].leng);
		sum+=a[i].leng;
		if(q.size()>k) sum+=q.top(),q.pop();
		ans=max(ans,a[i].bui*sum);
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}