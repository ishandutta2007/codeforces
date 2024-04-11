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
#define N 10
int c[N];
void work()
{
	int x=read(),y=read();
	for(int i=1;i<=6;i++) c[i]=read();
	int B=y-x,A=y-B;
	int r1=(A<0?c[4]:c[1])*abs(A)+(B<0?c[5]:c[2])*abs(B);
	B=x-y,A=x-B;
	int r2=(A<0?c[4]:c[1])*abs(A)+(B<0?c[3]:c[6])*abs(B);
	A=x,B=y;
	int r3=(A<0?c[3]:c[6])*abs(A)+(B<0?c[5]:c[2])*abs(B);
	cout<<min({r1,r2,r3})<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}