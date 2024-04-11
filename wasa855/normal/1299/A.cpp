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
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 100005
int a[N],n;
int sol(int k)
{
	int cnt=0,ans;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&(1<<k)) cnt++,ans=i;
	}
	if(cnt==1) return ans;
	return -1;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=31;i>=0;i--)
	{
		int ans=sol(i);
		if(ans!=-1)
		{
			cout<<a[ans]<<" ";
			for(int i=1;i<=n;i++)
			{
				if(i==ans) continue;
				printf("%d ",a[i]);
			}
			cout<<"\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]); cout<<"\n";
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}