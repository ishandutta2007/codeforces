#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int a[N],n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++)
	{
		int r=a[i]^a[i+1];
		if(i!=1&&r<a[i-1]) {cout<<1<<endl; return 0;}
		if(i!=n-1&&r>a[i+2]) {cout<<1<<endl; return 0;}
	}
	int ans=inf;
	for(int i=1;i<n;i++)
	{
		int tmp=0;
		for(int j=i;j>=1;j--)
		{
			tmp^=a[j]; int qaq=0;
			for(int k=i+1;k<=n;k++)
			{
				qaq^=a[k];
				if(tmp>qaq) ans=min(ans,k-j-1);
			}
		}
	}
	if(ans==inf) ans=-1;
	cout<<ans<<endl;
	return 0;
}