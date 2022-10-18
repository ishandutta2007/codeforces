#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
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
#define N 1005
struct Node
{
	int x,y;
};
bool cmp(Node x,Node y)
{
	return x.x<y.x;
}
Node a[N],b[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=i; sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) b[i].x=read(),b[i].y=i; sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++) printf("%d ",a[i].x); cout<<"\n";
	for(int i=1;i<=n;i++) printf("%d ",b[i].x); cout<<"\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}


//