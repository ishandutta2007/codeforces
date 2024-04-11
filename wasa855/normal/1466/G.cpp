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
#define mod 1000000007
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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 3000005
const int B=15381,i2=(mod+1)/2;
char str[N],t[N],s[N];
char w[N];
int n,Q,m,ans[N],len[N],pw2[N],ipw2[N],pw[N];
int hs[N],hw[N];
int hshs(int l,int r) {return sub(hs[r],mul(hs[l-1],pw[r-l+1]));}
int hsht(int l,int r) {return sub(hw[r],mul(hw[l-1],pw[r-l+1]));}
int sum[N/30+5][26];
signed main()
{
	cin>>n>>Q;
	scanf("%s%s",str+1,t+1);
	m=strlen(str+1);
	pw2[0]=1; for(int i=1;i<N;i++) pw2[i]=mul(pw2[i-1],2);
	ipw2[0]=1; for(int i=1;i<N;i++) ipw2[i]=mul(ipw2[i-1],i2);
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],B);
	for(int i=1;i<=m;i++) s[i]=str[i];
	len[0]=m; int tmp=0;
	while(m<=1000000)
	{
		tmp++; len[tmp]=len[tmp-1]*2+1;
		s[m+1]=t[tmp];
		for(int i=1;i<=m;i++) s[m+i+1]=s[i];
		m=len[tmp];
	}
	for(int i=1;i<=m;i++) hs[i]=add(mul(hs[i-1],B),s[i]);
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<26;j++) sum[i][j]=sum[i+1][j];
		sum[i][t[i]-'a']=add(sum[i][t[i]-'a'],pw2[n-i]);
	}
	while(Q--)
	{
		int k=read(); scanf("%s",w+1);
		int clen=strlen(w+1);
		if(k<=tmp&&len[k]<clen) {printf("0\n"); continue;}
		int pos=-1;
		for(int j=0;j<=tmp;j++) if(len[j]>=clen) {pos=j; break;}
		for(int j=1;j<=clen;j++) hw[j]=add(mul(hw[j-1],B),w[j]);
		int ans=0;
		for(int j=1;j+clen-1<=len[pos];j++) if(hshs(j,j+clen-1)==hsht(1,clen)) ans++;
		ans=mul(ans,pw2[k-pos]);
		
		for(int j=0;j<clen;j++)
		{
			if(hshs(m-j+1,m)!=hsht(1,j)) continue;
			if(hshs(1,clen-j-1)!=hsht(j+2,clen)) continue;
			int ned=w[j+1]-'a';
			int R=sub(sum[pos+1][ned],sum[k+1][ned]);
			ans=add(ans,mul(R,ipw2[n-k]));
		}
		printf("%d\n",ans);
	}
	return 0;
}