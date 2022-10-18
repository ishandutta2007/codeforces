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
#define N 200005
const int B=700;
int a[N],val[N*2],mx,n,ans=0;
vector<int> pos[N];
void solve1(int _val)
{
	memset(val,-1,sizeof(val));
	int cur=0;
	val[n]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mx) cur++;
		else if(a[i]==_val) cur--;
		if(val[cur+n]!=-1) ans=max(ans,i-val[cur+n]);
		else val[cur+n]=i;
	}
}

signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]].pb(i);
	for(int i=1;i<=n;i++) if(pos[i].size()>pos[mx].size()) mx=i;
	for(int i=1;i<=n;i++) if(pos[i].size()>=B) solve1(i);
	for(int c=1;c<=B;c++)
	{
		memset(val,0,sizeof(val));
		int pos=1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(val[a[i]]==c) cnt--;
			val[a[i]]++;
			if(val[a[i]]==c) cnt++;
			while(val[a[i]]>c)
			{
				if(val[a[pos]]==c) cnt--;
				val[a[pos]]--;
				if(val[a[pos]]==c) cnt++;
				pos++;
			}
			if(cnt>=2) ans=max(ans,i-pos+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}