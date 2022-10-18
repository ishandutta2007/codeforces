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
#define N 2005
char s[N];
void work()
{
	int n,m;
	cin>>n>>m;
	scanf("%s",s+1);
	vector<pii> v;
	for(int i=1;i<=n/2;i++)
	{
		if(s[i]=='(') continue;
		int j=i;
		while(s[j]==')') j++;
		v.pb(mp(i,j));
		reverse(s+i,s+j+1);
	}
	for(int i=1;i<m;i++)
	{
		int x=2*i;
		int j=x+1;
		while(j<=n&&s[j]=='(') j++;
		v.pb(mp(x,j));
		reverse(s+x,s+j+1);
	}
	cout<<v.size()<<endl;
	for(auto i:v)
	{
		printf("%d %d\n",i.fir,i.sec);
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}