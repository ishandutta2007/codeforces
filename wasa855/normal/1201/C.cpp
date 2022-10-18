#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int sum=0,k=0;
	for(int i=n/2+1;i<=n;i++)
	{
		sum+=a[i],k++;
		int res=(sum+m)/k;
		if(res<=a[i+1]||i==n)
		{
			cout<<res<<endl;
			return 0;
		}
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}