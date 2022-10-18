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
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--)
	{
		int b,p,f,h,c;
		cin>>b>>p>>f>>h>>c;
		int ans=0;
		for(int i=0;i<=100;i++)
		{
			if(p>=i&&b>=2*i)
			{
				ans=max(ans,i*h+min((b-2*i)/2,f)*c);
			}
		}
		cout<<ans<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}