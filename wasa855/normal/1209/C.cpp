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
int a[N];
int n; 
int r[N];
void work()
{
	n=read();
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	vector<int> v1,v2;
	for(int i=0;i<=10;i++)
	{
		bool ok=1;
		v1.clear(),v2.clear();
		for(int j=1;j<=n;j++)
		{
			if(a[j]>i)
			{
				if(v2.empty()) v2.pb(j);
				else
				{
					if(a[j]>=a[v2.back()]) v2.pb(j);
					else
					{
						ok=0;break;
					}
				}
			}
			else if(a[j]==i)
			{
				if(v2.empty()) v2.pb(j);
				else
				{
					if(a[j]>=a[v2.back()]) v2.pb(j);
					else
					{
						if(v1.empty()) v1.pb(j);
						else
						{
							if(a[j]>=a[v1.back()]) v1.pb(j);
							else
							{
								ok=0;break;
							}
						}
					}
				}
			}
			else
			{
				if(v1.empty()) v1.pb(j);
				else
				{
					if(a[j]>=a[v1.back()]) v1.pb(j);
					else
					{
						ok=0;break;
					}
				}
			}
		}
		if(ok==1)
		{
			for(auto j:v1) r[j]=1;
			for(auto j:v2) r[j]=2;
			for(int j=1;j<=n;j++) printf("%d",r[j]);
			cout<<"\n";
			return ;
		}
	}
	cout<<"-\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//sz