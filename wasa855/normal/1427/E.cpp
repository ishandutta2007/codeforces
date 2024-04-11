#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
struct Node
{
	int x; char opt; int y;
	Node(int a,char b,int c){x=a,opt=b,y=c;}
};
int n;
vector<Node> ans;
void exgcd(int x,int y,int &a,int &b)
{
	if(y==0) {a=1,b=0; return ;}
	exgcd(y,x%y,b,a);
	b-=x/y*a;
}
void getmul(int x,int y)
{
	if(y==1) return ;
	int tp=0;
	for(int i=60;i>=0;i--) if(y>>i&1) {tp=i; break;}
	int t=x;
	for(int i=1;i<=tp;i++) ans.eb(t,'+',t),t+=t;
	int las=-1,tmp=0;
	for(int i=0;i<=tp;i++)
	{
		if(y>>i&1)
		{
			if(las!=-1) ans.eb(tmp,'+',x<<i);
			las=i,tmp+=x<<i;
		}
	}
}
signed main()
{
	n=read();
	int x=n,y,t=n;
	while(1)
	{
		ans.eb(t,'+',t);
		t*=2;
		if(__gcd(t^n,n)==1)
		{
			ans.eb(t,'^',n);
			y=t^n;
			break;
		}
	}
	swap(x,y);
	// printf("%d %d\n",x,y);
	// return 0;
	int a,b;
	exgcd(x,y,a,b);
	b=-b;
	int A=(max(-a,0LL)+y-1)/y;
	int B=(max(-b,0LL)+x-1)/x;
	A=max(A,B);
	a+=A*y,b+=A*x;
	// printf("%d %d\n",a,b);
	// return 0;
	if(!(a&1)) a+=y,b+=x;
	getmul(x,a),getmul(y,b);
	ans.eb(x*a,'^',y*b);
	cout<<ans.size()<<endl;
	for(auto [x,y,z]:ans) printf("%lld %c %lld\n",x,y,z);
	return 0;
}