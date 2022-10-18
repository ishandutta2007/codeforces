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
#define int long long
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
#define N 35
int a[N],b[N],n,Q;
signed main()
{
	cin>>n>>Q;
	for(int i=0;i<n;i++) a[i]=read();
	while(Q--)
	{
		int op=read(),x=read(),k=read();
		if(op==1) a[x]=k;
		else
		{
			int sum=0,all=0;
			for(int j=0;j<=x;j++) sum+=a[j];
			for(int j=0;j<n;j++) all+=a[j]<<j;
			if(sum>=k) printf("0\n");
			else if(all<k) printf("-1\n");
			else
			{
				for(int j=0;j<n;j++) b[j]=a[j];
				// for(int j=0;j<n;j++) printf("%d%c",b[j]," \n"[j==n-1]);
				int ans=0,minn=INF;
				auto chk=[&]()
				{
					int curall=0;
					for(int j=0;j<=x;j++) curall+=b[j]<<j;
					if(curall>=k) minn=min(minn,ans+max(k-sum,0LL));
				};
				chk();
				for(int j=x+1;j<n;j++)
				{
					int ned=(1<<(j-x))-1,get=ned+1,go=min(b[j],(k-sum)/get);
					// printf("^ %d %d %d %d %d\n",j,x,ned,get,go);
					b[j]-=go,b[x]+=get*go,ans+=ned*go,sum+=get*go;
					chk();
					if(b[j]&&sum<k)
					{
						// cout<<"Passed\n";
						b[j]--,b[j-1]+=2,ans++;
						if(j==x+1) sum+=2;
						chk();
						for(int c=j-1;c>x;c--)
						{
							int ned=(1<<(c-x))-1,get=ned+1,go=min(b[c],(k-sum)/get);
							b[c]-=go,b[x]+=get*go,ans+=ned*go,sum+=get*go;
							chk();
							if(b[c]&&sum<k)
							{
								b[c]--,b[c-1]+=2,ans++;
								if(c==x+1) sum+=2;
							}
							chk();
						}
					}
				}
				if(sum>=k) printf("%lld\n",min(minn,ans));
				else printf("%lld\n",min(ans+k-sum,minn));
			}
		}
	}
	return 0;
}