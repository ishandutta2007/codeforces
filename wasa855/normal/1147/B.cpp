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
#define N 200005
int l[N],r[N];
map<pair<int,int>,bool> a;
int n,m;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		l[i]=read(),r[i]=read();
		a[mp(l[i]%n,r[i]%n)]=1;
		a[mp(r[i]%n,l[i]%n)]=1;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(n%i==0)
		{
//			cout<<i<<endl;
			bool ok=1;
			for(int j=1;j<=m;j++)
			{
//				printf("%d %d\n",(l[j]+i)%n,(r[j]+i)%n);
				if(a[mp((l[j]+i)%n,(r[j]+i)%n)]==0)
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				cout<<"Yes\n";
				return 0;
			}
		}
	}
	cout<<"No\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}


//