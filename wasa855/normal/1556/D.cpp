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
#define N 100005
int a[N];
int qor(int x,int y)
{
	printf("or %lld %lld\n",x,y); fflush(stdout);
	return read();
}
int qand(int x,int y)
{
	printf("and %lld %lld\n",x,y); fflush(stdout);
	return read();
}
int query(int x,int y)
{
	return qor(x,y)+qand(x,y);
}
signed main()
{
	int n=read(),k=read();
	int A=query(1,2),B=query(1,3),C=query(2,3);
	int t=(A+B+C)/2;
	a[1]=t-C,a[2]=t-B,a[3]=t-A;
	for(int i=4;i<=n;i++) a[i]=query(1,i)-a[1];
	sort(a+1,a+n+1);
	printf("finish %lld\n",a[k]);
	fflush(stdout);
	return 0;
}