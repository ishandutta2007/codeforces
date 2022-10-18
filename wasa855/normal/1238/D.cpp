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
#define N 300005
char s[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	scanf("%s",s+1);
	int sum=0;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=i;
		while(s[r+1]==s[l]&&r<n) r++;
		int res=r-l+1;
		if(l!=1) sum+=res;
		if(r!=n) sum+=res;
		i=r;
		tot++;
	}
	cout<<(n*(n-1)/2-sum+tot-1)<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}