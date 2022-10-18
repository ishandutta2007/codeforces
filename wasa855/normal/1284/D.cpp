#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int unsigned long long
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
	int id,x,d;
	Node(){}
	Node(int id,int x,int d):id(id),x(x),d(d){}
};
Node a1[N*2],a2[N*2];
int val[N];
int s[N];
bool cmp(Node x,Node y)
{
	if(x.d!=y.d) return x.d<y.d;
	return x.x>y.x;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int c=read(),d=read(),e=read(),f=read();
		a1[2*i-1]=Node(i,1,c);
		a1[2*i]=Node(i,0,d);
		a2[2*i-1]=Node(i,1,e);
		a2[2*i]=Node(i,0,f);
	}
	sort(a1+1,a1+n+n+1,cmp);
	sort(a2+1,a2+n+n+1,cmp);
	mt19937 rng(time(NULL));
	for(int i=1;i<=n;i++) val[i]=rng()<<31|rng();
	int sum=0;
	for(int i=1;i<=n+n;i++)
	{
		if(a1[i].x==0) sum^=val[a1[i].id];
		else s[a1[i].id]^=sum;
	}
	sum=0;
	for(int i=n+n;i>=1;i--)
	{
		if(a1[i].x==1) sum^=val[a1[i].id];
		else s[a1[i].id]^=sum;
	}
	sum=0;
	for(int i=1;i<=n+n;i++)
	{
		if(a2[i].x==0) sum^=val[a2[i].id];
		else s[a2[i].id]^=sum;
	}
	sum=0;
	for(int i=n+n;i>=1;i--)
	{
		if(a2[i].x==1) sum^=val[a2[i].id];
		else s[a2[i].id]^=sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=0)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//