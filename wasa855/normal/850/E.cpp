#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 1000000007
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int div2(int x){return x&1?(x+mod)>>1:x>>1;}
#define N 2000005
int a[N],n,pw[N];
void fwt(int a[],int typ)
{
	for(int i=1;i<(1<<n);i<<=1)
	{
		for(int j=0;j<(1<<n);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=add(x,y),a[i+j+k]=sub(x,y);
				if(typ==-1) a[j+k]=div2(a[j+k]),a[i+j+k]=div2(a[i+j+k]);
			}
		}
	}
}
signed main()
{
	cin>>n;
	for(int i=0;i<(1<<n);i++) scanf("%1d",&a[i]);
	pw[0]=1; for(int i=1;i<=(1<<n);i++) pw[i]=mul(pw[i-1],2);
	fwt(a,1);
	for(int i=0;i<(1<<n);i++) a[i]=mul(a[i],a[i]);
	fwt(a,-1);
	// for(int i=0;i<(1<<n);i++) printf("%d ",a[i]); cout<<"\n";
	int ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		ans=add(ans,mul(a[i],pw[n-__builtin_popcount(i)]));
	}
	cout<<mul(ans,3)<<endl;
	return 0;
}