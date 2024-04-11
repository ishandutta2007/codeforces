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

signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	string s; cin>>s;
	vector<int> a,b;
	int l=0,r=s.length()-1;
	while(l<r)
	{
		while(l<r&&s[l]==')') l++;
//		printf("%d %d\n",l,r);
		while(l<r&&s[r]=='(') r--;
//		printf("%d %d\n",l,r);
		if(l==r) break;
		a.pb(l),b.pb(r);
		l++,r--;
	}
	if(a.empty())
	{
		cout<<"0\n";
		return 0;
	}
	cout<<1<<endl;
	cout<<a.size()*2<<endl;
	for(int i=0;i<(int)a.size();i++) printf("%d ",a[i]+1);
	for(int i=(int)b.size()-1;i>=0;i--) printf("%d ",b[i]+1); cout<<"\n";
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}

//