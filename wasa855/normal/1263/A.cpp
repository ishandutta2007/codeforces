#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;

signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--)
	{
		int r,g,b;
		cin>>r>>g>>b;
		int ans=(r+b+g)/2;
		int tans=max(r,max(g,b));
		cout<<min(ans,r+b+g-tans)<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}