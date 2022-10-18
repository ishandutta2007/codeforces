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
inline ll read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	ll ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 20
int popcnt(int x) {return __builtin_popcount(x);}
int ctz(int x) {return __builtin_ctz(x);}
int f[1<<N],ok[1<<N],n,ful;
ll a[N],t[N],vl[1<<N],vr[1<<N];
ll div(ll x)
{
	if(x>=0) return x/2;
	else return -(-x+1)/2;
}
int chk(int st)
{
	int s=__builtin_popcount(st);
	if(s==1) return 0;
	int sl=s/2,sr=s-sl,cnt=0;
	for(int i=0;i<n;i++) if(st>>i&1) t[cnt++]=a[i];
	ll sum=0; for(int i=0;i<cnt;i++) sum+=t[i];
	// for(int i=0;i<s;i++) printf("%d%c",t[i]," \n"[i==s-1]);
	if((sum&1)==(s&1)) return 0;
	for(int i=1;i<1<<sl;i++)
	{
		int f=ctz(i);
		vl[i]=vl[i^(1<<f)]+t[f];
	}
	for(int i=1;i<1<<sr;i++)
	{
		int f=ctz(i);
		vr[i]=vr[i^(1<<f)]+t[f+sl];
	}
	sort(vl+1,vl+(1<<sl)),sort(vr+1,vr+(1<<sr));
	ll R=div(sum+s),L=sum-R; int pos=(1<<sr)-2;
	// printf("%d %d\n",L,R);
	// for(int i=1;i<1<<sl;i++) printf("%d ",vl[i]); cout<<"\n";
	// for(int i=1;i<1<<sl;i++) printf("%d ",vr[i]); cout<<"\n";
	for(int i=1;i<(1<<sl)-1;i++)
	{
		while(pos>=2&&vl[i]+vr[pos]>R) pos--;
		if(vl[i]+vr[pos]>R) break;
		if((i||pos)&&vl[i]+vr[pos]>=L) return 1;
	}
	for(int i=1;i<1<<sl;i++) if(vl[i]>=L&&vl[i]<=R) return 1;
	for(int i=1;i<1<<sr;i++) if(vr[i]>=L&&vr[i]<=R) return 1;
	return 0;
}
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		a[i]=read();
		if(!a[i]) n--,i--;
	}
	ful=(1<<n)-1;
	// cout<<chk(9)<<endl;
	// return 0;
	for(int i=1;i<1<<n;i++) ok[i]=chk(i);
	// cout<<ok[3]<<endl;
	// for(int i=1;i<1<<n;i++) if(ok[i]) printf("%d\n",i);
	for(int i=1;i<1<<n;i++)
	{
		if(ok[i])
		{
			f[i]=max(f[i],1); int qwq=ful^i;
			for(int j=qwq;j!=0;j=(j-1)&qwq) f[i|j]=max(f[i|j],f[i]+f[j]);
		}
	}
	// for(int i=1;i<1<<n;i++) printf("%d%c",f[i]," \n"[i==(1<<n)-1]);
	cout<<n-f[ful]<<endl;
	return 0;
}