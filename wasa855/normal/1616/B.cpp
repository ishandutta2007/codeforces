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
char s[N];
int n;
void work()
{
	n=read();
	scanf("%s",s+1);
	int pos=0,fl=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&s[i]>s[i-1]) break;
		else if(i!=1&&s[i]<s[i-1]) fl=1;
		else if(i!=1&&!fl) break;
		pos=i;
	}
	for(int i=1;i<=pos;i++) putchar(s[i]);
	for(int i=pos;i>=1;i--) putchar(s[i]);
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}