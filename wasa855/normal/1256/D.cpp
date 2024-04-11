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
#define N 1000005
char a[N];
void work()
{
	int n,k;
	cin>>n>>k;
	scanf("%s",a+1);
	int pre=0,res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='1') pre++;
		else
		{
			if(k>=pre)
			{
				swap(a[res+1],a[i]);
				res++;
				k-=pre;
			}
			else
			{
				swap(a[i],a[i-k]);
				break;
			}
		}
	}
	printf("%s\n",a+1);
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