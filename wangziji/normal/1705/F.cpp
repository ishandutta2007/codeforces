#include <bits/stdc++.h>
#define int long long
using namespace std;
const int B=10;
int nw[1005],n,XOR[1005],ANS[1005];
int TEST=0,CNT=0;
int ask()
{
	++CNT;
	for(int i=1;i<=n;i++)
	{
		if(nw[i]^XOR[i]) cout << "T";
		else cout << "F";
	}
	cout << endl;
	int x=0;
	if(!TEST) cin >> x;
	else
	{
		for(int i=1;i<=n;i++)
			x+=ANS[i]==(nw[i]^XOR[i]);
	}
	if(x==n)
	{
		cerr << CNT << "\n";
		exit(0);
	}
	return x;
}
int qwq;
int vis[1<<B];
int cnt(int x)
{
	if(!x) return 0;
	return cnt(x^x&-x)+1;
}
int C0=0;
int w(vector<int>v,int x,int len)
{
	int C[20]={},rtn=0;
	for(auto t:v)
		rtn+=++C[len-cnt(t^x)];
	return rtn;
}
void solve(int l,int r)
{
	for(int i=l;i<=r;i++) nw[i]=1;
	int A=(1<<r-l+1)-1;
	for(int i=0;i<(1<<r-l+1);i++) vis[i]=1;
	int x=ask();
	int s=((x+qwq-l+1-C0)-(r-l+1))/2+l-1;
//	cout << s << "*******\n";
	x-=s;
	int qaq=(1<<r-l+1);
	while(1)
	{
		for(int i=0;i<(1<<r-l+1);i++)
			if(vis[i]&&(r-l+1)-cnt(i^A)!=x) vis[i]=0,--qaq;
		if(qaq<=1) break;
		A=0;
		vector <int> v;
		for(int i=0;i<(1<<r-l+1);i++)
			if(vis[i]) v.push_back(i);
		int T=20,mn=1e9;
		while(T--)
		{
			int R=(rand()&(1<<r-l+1)-1);
			int x=w(v,R,r-l+1);
			if(x<mn) mn=x,A=R;
		}
		for(int j=0;j<r-l+1;j++)
		{
			nw[l+j]=(A>>j)&1;
//			A|=(nw[l+j]<<j);
		}
		x=ask()-s;
	}
	int P=0;
	for(int i=0;i<(1<<r-l+1);i++)
	{
		if(vis[i]) P=i;
	}
	for(int i=0;i<(r-l+1);i++)
	{
		if(P&(1<<i)) nw[i+l]=1;
		else nw[i+l]=0,++C0;
	}
}
signed main()
{
	srand((unsigned long long)new char);
	srand((unsigned long long)rand()^time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(TEST)
	{
		for(int i=1;i<=n;i++)
		{
	/*		char c;
			cin >> c;
			ANS[i]=c-'0';*/
			ANS[i]=rand()&1;
		}
	}
	for(int i=1;i<=n;i++) XOR[i]=rand()&1;
	qwq=ask();
	int l=1,r=min(n,l+B-1);
	while(l<=n)
	{
	//	cout << l << "*" << r << "\n";
		solve(l,r);
		l=r+1,r=min(n,l+B-1);
	}
	ask();
	return 0;
 }