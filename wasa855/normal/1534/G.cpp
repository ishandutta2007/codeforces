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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 800005
struct Node{int x,y;};
Node a[N];
bool cmp(Node x,Node y) {return x.x<y.x;}
int n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]=(Node){x+y,x};
	}
	sort(a+1,a+n+1,cmp);
	multiset<int> sl,sr;
	int val=0,tag=0;
	sl.insert(-1),sr.insert(inf);
	for(int i=1;i<=n;i++)
	{
		int d=a[i].x-a[i-1].x,l=*sl.rbegin(),r=*sr.begin()+tag+d;
		tag+=d;
		if(a[i].y<=l)
		{
			sl.erase(--sl.end()),sl.insert(a[i].y),sl.insert(a[i].y);
			sr.insert(l-tag);
			val+=abs(a[i].y-l);
		}
		else if(a[i].y>=r)
		{
			sr.erase(sr.begin()),sr.insert(a[i].y-tag),sr.insert(a[i].y-tag);
			sl.insert(r),val+=abs(a[i].y-r);
		}
		else
		{
			sl.insert(a[i].y),sr.insert(a[i].y-tag);
		}
	}
	cout<<val<<endl;
	return 0;
}