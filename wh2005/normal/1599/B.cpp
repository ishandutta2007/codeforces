#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=3005;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,A,B,x,y;
int ans;
string a,b;
bool flag=0;
void DOIT()
{
	rd(n);rd(A);rd(B);A++;B++;x=0;y=0;
	cin>>a>>b;flag=0;//0 1 
	if (A>B)
	{
		if (a=="left") A--;else A++;if (A==0) A=2;if (A==n+1) A=n-1;
		swap(A,B);swap(a,b);
	}
	if (A==1 && B==1) {cout<<n-1<<endl;return;}
	if (A==1 && B==2) {cout<<0<<endl;return;}
	if (A==n) {cout<<0<<endl;return;}
	if (A==n-1) {cout<<0<<endl;return;}
	if (A<B)
	{
		if (a=="right" && b=="left") {flag=(B-A+1)%2;x=(A+B+1)/2-1;y=n-x-1;}
		if (a=="left" && b=="left") 
		{
			B-=A-1;A=1;
			if (A==1 && B==1) {cout<<n-1<<endl;return;}
			if (A==1 && B==2) {cout<<0<<endl;return;}
			flag=(B-A+1)%2;x=(A+B+1)/2-1;y=n-x-1;
		}
		if (a=="right" && b=="right") 
		{
			A+=n-B;B=n;
			if (A==n) {cout<<0<<endl;return;}
			if (A==n-1) {cout<<0<<endl;return;}
			flag=(B-A+1)%2;x=(A+B+1)/2-1;y=n-x-1;
		}
		if (a=="left" && b=="right")
		{
			int t=max(A-1,n-B);
			A-=t;if (A<1) A=2-A;
			B+=t;if (B>n) B=2*n-B;
			if (A==1 && B==1) {cout<<n-1<<endl;return;}
			if (A==1 && B==2) {cout<<0<<endl;return;}
			if (B==n && A==n) {cout<<0<<endl;return;}
			if (B==n && A==n-1) {cout<<n-1<<endl;return;}
			flag=(B-A+1)%2;x=(A+B+1)/2-1;y=n-x-1;
		}
	} else 
	if (A==B)
	{
		x=A-1;y=n-x-1;
		if (a=="left" && b=="right") {flag=0;}
		if (a=="left" && b=="left") {cout<<n-1<<endl;return;}
		if (a=="right" && b=="right") {cout<<0<<endl;return;}
		if (a=="right" && b=="left") {flag=1;}
	}
	//cout<<"x="<<x<<" flag="<<flag<<endl;
	if (flag) {swap(x,y);ans=0;}else ans=1;
	
	if (ans) cout<<0<<endl;else cout<<n-1<<endl;
	
}
signed main()
{
	int JYZ;rd(JYZ);while (JYZ--) DOIT();
}

/*

*/