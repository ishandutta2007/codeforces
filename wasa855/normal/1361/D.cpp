#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
map<pii,vector<double>> v;
signed main()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(x==0&&y==0) continue;
		int k=__gcd(x,y);
		if(k<0) k=-k;
		int a=x/k,b=y/k;
		v[mp(a,b)].pb(sqrt(1LL*x*x+1LL*y*y));
	}
	vector<double> ans;
	ans.pb(0);
	for(auto [__,b]:v)
	{
		sort(b.begin(),b.end());
		// printf("%d %d :\n",__.fir,__.sec);
		// for(auto i:b)  printf("%lf ",i); cout<<"\n";
		int l=0,r=(int)b.size()-1;
		double dl=0,dr=0,A=0,B=0;
		for(int i=0;i<(int)b.size();i++)
		{
			if(i<k/2)
			{
				A+=dr-i*b[r];
				dr+=b[r];
				r--;
			}
			else
			{
				A+=dr-(k/2)*b[l]+b[l]*(i-k/2)-dl;
				// printf("%d %lf\n",i,A);
				dl+=b[l];
				l++;
			}
			double tmp=A+(dl+dr)*(k-i-1);
			// printf("%d %lf\n",i,tmp);
			ans.pb(tmp-B);
			B=tmp;
		}
	}
	// for(auto i:ans) printf("%lf\n",i);
	sort(ans.begin(),ans.end(),[&](double x,double y){return x>y;});
	double sum=0;
	for(int i=0;i<k;i++) sum+=ans[i];
	printf("%.6lf\n",sum);
	return 0;
}