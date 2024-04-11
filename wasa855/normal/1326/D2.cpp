#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 2000050
int p[N];
string solve(string s)
{
	string t=s;
	reverse(t.begin(),t.end());
	t=s+'*'+t;
	int tmp=0;
	for(int i=1;i<t.size();i++)
	{
		while(tmp&&t[tmp]!=t[i]) tmp=p[tmp-1];
		if(t[tmp]==t[i]) tmp++;
		p[i]=tmp;
	}
	return s.substr(0,tmp);
}
void work()
{
	string s;
	cin>>s;
	int l=0;
	while(l<(int)s.length()-l-1)
	{
		if(s[l]!=s[(int)s.length()-l-1]) break;
		l++;
	}
	if(l) cout<<s.substr(0,l);
	if(s.length()>2*l)
	{
		string t=s.substr(l,s.length()-l-l);
		string a=solve(t);
		reverse(t.begin(),t.end());
		string b=solve(t);
		if(a.length()>b.length()) cout<<a;
		else cout<<b;
	}
	if(l) cout<<s.substr(s.length()-l,l);
	cout<<"\n";
}
signed main()
{
	Fast_IO;
	int T; cin>>T;
	while(T--) work();
	return 0;
}