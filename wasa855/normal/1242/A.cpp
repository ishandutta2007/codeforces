#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int p=0;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(p!=0)
			{
				cout<<"1\n";
				return 0;
			}
			p=i;
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(p==0) return cout<<n<<endl,0;
	if(n!=1) cout<<1<<endl;
	else cout<<p<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}