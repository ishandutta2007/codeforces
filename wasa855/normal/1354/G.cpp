#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
char re[255];
int query()
{
	char s[10];
	scanf("%s",s);
	if(s[0]=='W') exit(5);
	return re[s[0]];
}
void work()
{
	int n=read(),k=read();
	for(int i=1;i<=30;i++)
	{
		int q=rnd()%(n-1)+2;
		printf("? 1 1\n");
		printf("%d\n%d\n",1,q);
		fflush(stdout);
		int r=query();
		if(r==2)
		{
			cout<<"! 1"<<endl;
			return ;
		}
	}
	int t=1;
	while(t*2<=n)
	{
		printf("? %d %d\n",t,t);
		for(int i=1;i<=t;i++) printf("%d ",i); cout<<"\n";
		for(int i=t+1;i<=t+t;i++) printf("%d ",i); cout<<endl;
		int r=query();
		if(r==1) break;
		t*=2;
	}
	int l=t+1,r=min(t+t,n),ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		printf("? %d %d\n",mid-t,mid-t);
		for(int i=1;i<=mid-t;i++) printf("%d ",i); cout<<"\n";
		for(int i=t+1;i<=mid;i++) printf("%d ",i); cout<<endl;
		int re=query();
		if(re==1) ans=mid,r=mid-1;
		else l=mid+1; 
	}
	printf("! %d\n",ans);
	fflush(stdout);
}
signed main()
{
	re['F']=1,re['S']=2,re['E']=3,re['W']=4;
	int T=read();
	while(T--) work(); 
	return 0;
}