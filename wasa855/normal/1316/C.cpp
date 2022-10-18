#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1000005
int a[N],b[N];
signed main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++) a[i]=read();
	for(int j=0;j<m;j++) b[j]=read();
	int l=0,r=0;
	while(a[l]%p==0) l++;
	while(b[r]%p==0) r++;
	cout<<l+r<<endl;
	return 0;
}


//