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
	for(int i=1;i<=n;i++) a[i]=read();
	int sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
	if(sum%2==1||maxn*2>sum) cout<<"NO\n";
	else cout<<"YES\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}