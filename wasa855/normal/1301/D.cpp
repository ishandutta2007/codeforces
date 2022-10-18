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
	int n,m,k;
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m)
	{
		cout<<"NO\n";
		return 0;
	}
	vector<pair<int,string> > ans;
	if(k<m) {ans.pb(mp(k,"R")); goto end;}
	if((m-1)!=0) ans.pb(mp(m-1,"R")); k-=m-1;
	if(k<m) {ans.pb(mp(k,"L")); goto end;}
	if((m-1)!=0) ans.pb(mp(m-1,"L")); k-=m-1;
	for(int i=2;i<=n;i++)
	{
		if(k==0) goto end;
		ans.pb(mp(1,"D")); k--;
		if(k==0) goto end;
		if(k>=4*(m-1))
		{
			if((m-1)!=0) ans.pb(mp(m-1,"RUD"));
			if((m-1)!=0) ans.pb(mp(m-1,"L"));
			k-=4*(m-1);
			continue;
		}
		if(k>=3*(m-1))
		{
			if((m-1)!=0) ans.pb(mp(m-1,"RUD"));
			k-=3*(m-1);
			if(k!=0) ans.pb(mp(k,"L"));
			goto end;
		}
		int go=k/3;
		if(go!=0) ans.pb(mp(go,"RUD"));
		k-=3*go;
		if(k==1) ans.pb(mp(1,"R"));
		if(k==2) ans.pb(mp(1,"RU"));
		goto end;
	}
	if(k!=0) ans.pb(mp(k,"U"));
	end:;
	cout<<"YES\n";
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].fir<<" "<<ans[i].sec<<"\n";
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}