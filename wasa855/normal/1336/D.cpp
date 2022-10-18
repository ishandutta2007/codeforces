#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 105
int n,cnt;
int a[N][2],t[N][2],ans[N];
void query(int x)
{
	cout<<"+ "<<x<<endl;
	cnt++;
	t[cnt][0]=read(),t[cnt][1]=read();
	a[cnt][0]=t[cnt][0]-t[cnt-1][0],a[cnt][1]=t[cnt][1]-t[cnt-1][1];
}
int get(int x)
{
//	cout<<x<<endl;
	if(x==0) return -1;
	for(int i=2;i<=200;i++)
	{
		if(i*(i-1)/2==x) return i;
	}
	assert(0);
}
signed main()
{
	memset(ans,-1,sizeof(ans));
	cin>>n;
	cin>>t[0][0]>>t[0][1];
	query(1),query(2),query(3),query(1);
	ans[1]=get(a[1][0]);
	if(ans[1]==-1)
	{
		if(a[4][0]==1) ans[1]=1;
		else ans[1]=0;
	}
	ans[2]=get(a[2][0]);
	ans[3]=get(a[3][0]);
//	cout<<"Passed\n";
	if(ans[2]==-1&&ans[3]==-1)
	{
		if(a[1][1]!=0) ans[2]=ans[3]=1;
		else if(a[4][1]==1) ans[2]=ans[3]=0;
		else if(a[2][1]==0) ans[3]=0,ans[2]=1;
		else ans[2]=0,ans[3]=1;
	}
	if(ans[2]==-1)
	{
		if(a[1][1]) ans[2]=1;
		else ans[2]=0;
	}
	if(ans[3]==-1)
	{
		if(a[1][1]) ans[3]=1;
		else ans[3]=0;
	}
	int las=a[3][1]-(ans[1]+1)*(ans[2]+1);
	for(int i=4;i<n;i++)
	{
		query(i);
		ans[i]=get(a[i+1][0]);
		if(ans[i]==-1)
		{
			if(las) ans[i]=1;
			else ans[i]=0;
		}
		las=a[i+1][1]-(ans[i-1]+1)*(ans[i-2]+1);
	}
	ans[n]=las/(ans[n-2]+1);
	cout<<"! ";
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	cout<<endl;
	return 0;
}