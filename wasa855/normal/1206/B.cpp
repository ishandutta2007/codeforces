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
#define N 100005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	int ans=0;
	int z=0;
	int na=0,p=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<0) ans+=(-1-a[i]),p++;
		else if(a[i]>0) ans+=(a[i]-1),na++;
		else z++;
	}
	if(p%2==0)
	{
		cout<<ans+z<<endl;
	}
	else
	{
		if(z!=0) cout<<ans+z<<endl;
		else cout<<ans+2<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//asc