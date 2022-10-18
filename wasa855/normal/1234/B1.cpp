#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
queue<int> q;
map<int,bool> vis;
int ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(vis[a[i]]) continue;
		if(q.size()<k) {q.push(a[i]);vis[a[i]]=true;continue;}
		vis[q.front()]=0;
		q.pop();
		q.push(a[i]);vis[a[i]]=1;
//		cout<<i<<endl;
	}
//	cout<<q.front()<<endl;
	cout<<q.size()<<endl;
	int cnt=0;
	while(!q.empty()) ans[++cnt]=q.front(),q.pop();
	for(int i=cnt;i>=1;i--) printf("%d ",ans[i]);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}