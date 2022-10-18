#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 505
int a[N],sum[N];
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++) a[i]=i;
	int maxn=0,ans;
	for(int i=k+1;i>=1;i--)
	{
		a[i]++;
		printf("? ");
		for(int j=1;j<=k;j++) printf("%d ",a[j]);
		cout<<"\n"; fflush(stdout);
		int x=read(),y=read();
		sum[x]++;
		if(maxn<y) maxn=y,ans=x;
	}
	printf("! %d\n",sum[ans]);
	cout<<"\n"; fflush(stdout);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}