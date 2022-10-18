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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
void print(__int128 x)
{
	if(x<=9) putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}
#define N 600005
char s[N];
int fa[N],anc[N],w[N],st[N],tp,n;
map<int,int> cnt;
signed main()
{
	cin>>n;
	s[1]=rdchar(),w[1]=read();
	__int128 ans=w[1]; print(ans),puts("");
	st[++tp]=1;
	ll dif=0;
	for(int i=2;i<=n;i++)
	{
		s[i]=rdchar(),w[i]=read()^(ans&((1<<30)-1));
		s[i]=(s[i]-'a'+ans%26)%26+'a';
		int tmp=fa[i-1];
		anc[i-1]=s[tmp+1]==s[i]?anc[tmp]:tmp;
		while(tmp&&s[tmp+1]!=s[i]) tmp=fa[tmp];
		if(s[tmp+1]==s[i]) tmp++;
		fa[i]=tmp;
		tmp=fa[i-1];
		while(tmp)
		{
			if(s[i]==s[tmp+1])
			{
				tmp=anc[tmp];
				continue;
			}
			int v=w[*lower_bound(st+1,st+tp+1,i-tmp)];
			dif-=v,tmp=fa[tmp],cnt[v]--;
		}
		if(s[1]==s[i]) cnt[w[i]]++,dif+=w[i];
		while(tp&&w[st[tp]]>=w[i]) tp--;
		st[++tp]=i;
		while(!cnt.empty()&&cnt.rbegin()->fir>w[i])
		{
			dif-=1LL*(cnt.rbegin()->fir-w[i])*cnt.rbegin()->sec;
			cnt[w[i]]+=cnt.rbegin()->sec;
			cnt.erase(--cnt.end());
		}
		ans+=dif;
		// printf("%lld ",dif);
		ans+=w[st[1]];
		print(ans),puts("");
	}
	// printf("%s\n",s+1);
	// for(int i=1;i<=n;i++) printf("%d%c",fa[i]," \n"[i==n]);
	// for(int i=1;i<=n;i++) printf("%d%c",w[i]," \n"[i==n]);
	return 0;
}