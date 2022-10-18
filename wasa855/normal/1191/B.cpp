#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
struct Node
{
	int dat;
	char opt;
};
Node a[4];
bool cmp(Node x,Node y)
{
	if(x.opt==y.opt) return x.dat<y.dat;
	else return x.opt<y.opt;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%1d",&a[1].dat);
	cin>>a[1].opt;
	scanf("%1d",&a[2].dat);
	cin>>a[2].opt;
	scanf("%1d",&a[3].dat);
	cin>>a[3].opt;
	sort(a+1,a+3+1,cmp);
	if(a[1].opt==a[2].opt&&a[2].opt==a[3].opt)
	{
		if(a[1].dat==a[2].dat&&a[2].dat==a[3].dat)
		{
			cout<<"0\n";return 0;
		}
		if(a[1].dat+1==a[2].dat&&a[2].dat+1==a[3].dat)
		{
			cout<<"0\n";return 0;
		}
		if(a[1].dat==a[2].dat||a[2].dat==a[3].dat)
		{
			cout<<"1\n";return 0;
		}
		if(a[1].dat+1==a[2].dat||a[1].dat+2==a[2].dat)
		{
			cout<<"1\n";return 0;
		}
		if(a[2].dat+1==a[3].dat||a[2].dat+2==a[3].dat)
		{
			cout<<"1\n";return 0;
		}
		cout<<"2\n";return 0;
	}
	if(a[1].opt==a[2].opt)
	{
		if(abs(a[1].dat-a[2].dat)<=2)
		{
			cout<<"1\n";return 0;
		}
		cout<<"2\n";return 0;
	}
	if(a[2].opt==a[3].opt)
	{
		if(abs(a[2].dat-a[3].dat)<=2)
		{
			cout<<"1\n";return 0;
		}
		cout<<"2\n";return 0;
	}
	cout<<"2\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}