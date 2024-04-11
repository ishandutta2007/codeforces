#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
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
typedef pair<double,double> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define pi acos(-1)
pii operator + (pii x,pii y)
{
	pii R;
	R.fir=x.fir+y.fir;
	R.sec=x.sec+y.sec;
	return R;
}
pii trans(pii x)
{
	return mp(x.sec*cos(x.fir),x.sec*sin(x.fir));
}
void print(pii x)
{
	printf("%lf %lf\n",x.fir,x.sec);
}
signed main()
{
	int n=read();
	if(n<=4)
	{
		cout<<"No solution\n";
		return 0;
	}
	double a=2*pi/n;
	pii cur=mp(0,0),v=mp(a,700);
	print(cur);
	for(int i=1;i<n-1;i++)
	{
		cur=cur+trans(v);
		print(cur);
		v.fir+=a; v.sec+=0.01;
	}
	double x=cur.sec/tan(a);
	cur.fir+=x,cur.sec=0;
	print(cur);
	return 0;
}