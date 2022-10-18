#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void work()
{
	int a,b;
	cin>>a>>b;
	int n=abs(a-b);
	int l=0,r=1e6,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid*(mid+1)/2>=n) r=mid-1,ans=mid;
		else l=mid+1;
	}
//	cout<<ans<<endl;
//	cout<<ans*(ans+1)/2+n<<endl;
	while((ans*(ans+1)/2+n)%2==1) ans++;
	cout<<ans<<endl;
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