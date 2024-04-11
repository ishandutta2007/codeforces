#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
//#define int long long
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
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			a[i]=(cnt<<1)-1;
			a[i+n]=cnt<<1;
		}
		else
		{
			a[i+n]=(cnt<<1)-1;
			a[i]=cnt<<1;
		}
		cnt++;
	}
	for(int i=1;i<=n*2;i++)
	{
		printf("%d ",a[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//awf