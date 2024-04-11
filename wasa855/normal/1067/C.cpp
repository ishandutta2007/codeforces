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
void print(int x,int y) {printf("%d %d\n",x,y);}
signed main()
{
	int n=read();
	if(n<=6)
	{
		for(int i=1;i<=n;i++) print(i,0);
		return 0;
	}
	int g=n/3;
	print(0,0),print(0,1),print(0,2);
	for(int i=1;i<=g-2;i++) print(i*2,0),print(i*2-1,1),print(i*2,2);
	print(g*2-3,0),print(g*2-3,1),print(g*2-3,2);
	for(int i=0;i<n%3;i++) print(i,5);
	return 0;
}