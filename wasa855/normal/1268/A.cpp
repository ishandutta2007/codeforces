#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int a[N],b[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=k;i++) b[i]=a[i];
	for(int i=k+1;i<=n;i++) b[i]=b[i-k];
	bool lar=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			lar=0;break;
		}
		if(a[i]<b[i]) break;
	}
	if(lar)
	{
		cout<<n<<endl;
		for(int i=1;i<=n;i++) printf("%d",b[i]); cout<<"\n";
	}
	else
	{
		b[k]++;
		int i=k;
		while(b[i]>=10) b[i]-=10,b[i-1]++,i--;
		for(int i=k+1;i<=n;i++) b[i]=b[i-k];
		cout<<n<<endl;
		for(int i=1;i<=n;i++) printf("%d",b[i]); cout<<"\n";
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}