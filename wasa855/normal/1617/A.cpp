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
#define N 105
char s[N],t[N];
void work()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1);
	int cnt[4]={0,0,0,0};
	for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
	if(t[1]!='a'||(t[1]=='a'&&t[2]=='c'))
	{
		sort(s+1,s+n+1);
		printf("%s\n",s+1);
	}
	else
	{
		int cnt[27]; memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
		int fl=cnt[0];
		while(cnt[0]) putchar('a'),cnt[0]--;
		if(fl)
		{
			while(cnt[2]) putchar('c'),cnt[2]--;
			while(cnt[1]) putchar('b'),cnt[1]--;
		}
		else
		{
			while(cnt[1]) putchar('b'),cnt[1]--;
			while(cnt[2]) putchar('c'),cnt[2]--;
		}
		for(int i=3;i<26;i++) while(cnt[i]) putchar(i+'a'),cnt[i]--;
		printf("\n");
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}