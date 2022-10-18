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
#define N 25
string s[N],t[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<m;i++) cin>>t[i];
	int T=read();
	while(T--)
	{
		int x=read();
		cout<<s[(x-1)%n]<<t[(x-1)%m]<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}