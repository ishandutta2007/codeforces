/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("unroll-loops")*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int M=14;
const int SZ=62;
const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
void ADD(int &x, int y){ x=add(x,y);}
int a[N][M];
char s[N][M];
//int dp4[SZ][SZ][SZ][SZ];
int dp3[SZ][SZ][SZ];
map<string,bool> was;
int dp2[SZ][SZ];
int sol;
vector<pair<int,int>> use;
int mx;
void Solve(vector<int> v, int ways)
{
	//if(v.size()==8){ ADD(sol,ways);return;}
	//printf("%i %i: ",v.size(),ways);
	//for(int i:v) printf("%i ",i);printf("\n");
	if(v.size()==2 || v.size()==4)
	{
		for(auto p:use)
		{
			int i=p.first;
			int j=p.second;
			int tmp=mul(dp2[i][j],mul(dp2[v[0]][i],dp2[v[1]][j]));
			if(tmp)
			{
				vector<int> u=v;
				u.pb(i);
				u.pb(j);
				Solve(u,mul(ways,tmp));
			}
		}
	}
	if(v.size()==6)
	{
		for(auto p:use)
		{
			int i=p.first;
			int j=p.second;
			int tmp=mul(dp2[i][j],mul(dp2[v[4]][i],dp2[v[5]][j]));
			tmp=mul(tmp,mul(dp2[v[2]][i],dp2[v[3]][j]));
			if(tmp)
			{
				//printf("i:%i j:%i tmp:%i\n",i,j,tmp);
				ADD(sol,mul(ways,tmp));
				//Solve(u,mul(ways,tmp));
			}
		}
	}
}
void Solve(int len, vector<int> ids)
{
	for(int i=0;i<=mx;i++) for(int j=0;j<=mx;j++) dp2[i][j]=0;
	for(int i:ids)
	{
		bool pal=1;
		for(int j=1;j<=len;j++) if(a[i][j]!=a[i][len-j+1]) pal=0;
		dp2[a[i][len]][a[i][1]]++;
		//printf("%i %i\n",a[i][len],a[i][1]);
		if(!pal) dp2[a[i][1]][a[i][len]]++;
	}
	for(int i=0;i<=mx;++i) for(int j=0;j<=mx;++j) for(int k=0;k<=mx;++k) dp3[i][j][k]=0;
	for(int i=0;i<=mx;++i) for(int j=i;j<=mx;++j) for(int k=j;k<=mx;++k) for(int z=0;z<=mx;++z)
	{
		ll tmp=(ll)dp2[i][z]*dp2[j][z]%mod*dp2[k][z]%mod;
		ADD(dp3[i][j][k],tmp);
	}
	int FAC[5]={1,1,2,6,24};
	for(int i=0;i<=mx;++i) for(int j=i;j<=mx;++j) for(int k=j;k<=mx;++k) for(int z=k;z<=mx;++z)
	{
	    ll per=24;
	    /*vector<int> arr;
	    arr.pb(i);
	    arr.pb(j);
	    arr.pb(k);
	    arr.pb(z);
	    int sz=0;
	    for(int l=0;l<4;l++)
		{
			sz++;
			if(l==0 || arr[l]!=arr[l-1]) sz=1;
			if(l==3 || arr[l]!=arr[l+1]) per/=FAC[sz];
		}*/
	    if(i==j && j==k && k==z) per=1;
	    else if(i==j && j==k) per=4;
	    else if(i!=j && j==k && k==z) per=4;
	    else if(i==j && k==z) per=6;
	    else if(i==j || k==z) per/=2;
	    else if(j==k) per/=2;
		ll tmp=(ll)dp3[i][j][k]*dp3[i][j][z]%mod*dp3[i][k][z]%mod*dp3[j][k][z]%mod*per%mod;
		ADD(sol,tmp);
	}
	/*use.clear();
	for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++)
	{
		if(dp2[i][j])
		{
			use.pb({i,j});
		}
	}
	for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++)
	{
		if(dp2[i][j])
		{
			vector<int> v;
			v.pb(i);
			v.pb(j);
			Solve(v,dp2[i][j]);
		}
	}*/
	/*for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++) for(int k=0;k<SZ;k++) for(int l=0;l<SZ;l++)
	{
        dp4[i][j][k][l]=mul(mul(dp2[i][j],dp2[k][l]),mul(dp2[i][k],dp2[j][l]));
	}
	//printf("%i\n",dp4[0][0][0][0]);
	int ans=0;
	for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++) for(int k=0;k<SZ;k++) for(int l=0;l<SZ;l++)
	for(int i2=0;i2<SZ;i2++) for(int j2=0;j2<SZ;j2++) for(int k2=0;k2<SZ;k2++) for(int l2=0;l2<SZ;l2++)
	{
		ADD(ans,mul(mul(dp4[i][j][k][l],dp4[i2][j2][k2][l2]),mul(mul(dp2[i][i2],dp2[j][j2]),mul(dp2[k][k2],dp2[l][l2]))));
	}
	return ans;*/
}
int Get(char c)
{
	if(c>='a' && c<='z') return c-'a';
	if(c>='A' && c<='Z') return c-'A'+26;
	return c-'0'+52;
}
vector<int> all[M];
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	//scanf("%i",&n);
	cin>>n;
	vector<string> vec;
	for(int i=1;i<=n;i++)
	{
		//scanf("%s",s[i]+1);
		//int len=strlen(s[i]+1);
		string tmp;
		cin>>tmp;
		//for(int j=1;j<=len;j++) tmp+=s[i][j];
		string rev=tmp;
		reverse(rev.begin(),rev.end());
		if(tmp.compare(rev)<0) vec.pb(tmp);
		else vec.pb(rev);
		/*reverse(tmp.begin(),tmp.end());
		if(!was[tmp])
		{
			reverse(tmp.begin(),tmp.end());
			was[tmp]=1;
			for(int j=1;j<=len;j++) a[i][j]=Get(s[i][j]),mx=max(mx,a[i][j]);
			all[len].push_back(i);
		}*/
	}
	sort(vec.begin(),vec.end());
	int sz=0;
	for(int i=1;i<n;i++) if(vec[i]!=vec[sz]) vec[++sz]=vec[i];
	for(int i=0;i<=sz;i++)
	{
		for(int j=0;j<vec[i].size();j++) a[i+1][j+1]=Get(vec[i][j]),mx=max(mx,a[i+1][j+1]);
		all[vec[i].size()].pb(i+1);
		//cout<<vec[i]<<"\n";
	}
	//int ans=0;
	for(int i=1;i<=10;i++) if(all[i].size()) Solve(i,all[i]);
	//printf("%i\n",sol);
	cout<<sol;
	return 0;
}
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int M=14;
const int SZ=62;
const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
void ADD(int &x, int y){ x=add(x,y);}
int a[N][M];
char s[N][M];
//int dp4[SZ][SZ][SZ][SZ];
int dp3[SZ][SZ][SZ];
map<string,bool> was;
int dp2[SZ][SZ];
int sol;
vector<pair<int,int>> use;
int mx;
void Solve(vector<int> v, int ways)
{
	//if(v.size()==8){ ADD(sol,ways);return;}
	//printf("%i %i: ",v.size(),ways);
	//for(int i:v) printf("%i ",i);printf("\n");
	if(v.size()==2 || v.size()==4)
	{
		for(auto p:use)
		{
			int i=p.first;
			int j=p.second;
			int tmp=mul(dp2[i][j],mul(dp2[v[0]][i],dp2[v[1]][j]));
			if(tmp)
			{
				vector<int> u=v;
				u.pb(i);
				u.pb(j);
				Solve(u,mul(ways,tmp));
			}
		}
	}
	if(v.size()==6)
	{
		for(auto p:use)
		{
			int i=p.first;
			int j=p.second;
			int tmp=mul(dp2[i][j],mul(dp2[v[4]][i],dp2[v[5]][j]));
			tmp=mul(tmp,mul(dp2[v[2]][i],dp2[v[3]][j]));
			if(tmp)
			{
				//printf("i:%i j:%i tmp:%i\n",i,j,tmp);
				ADD(sol,mul(ways,tmp));
				//Solve(u,mul(ways,tmp));
			}
		}
	}
}
void Solve(int len, vector<int> ids)
{
	for(int i=0;i<=mx;i++) for(int j=0;j<=mx;j++) dp2[i][j]=0;
	for(int i:ids)
	{
		bool pal=1;
		for(int j=1;j<=len;j++) if(a[i][j]!=a[i][len-j+1]) pal=0;
		dp2[a[i][len]][a[i][1]]++;
		//printf("%i %i\n",a[i][len],a[i][1]);
		if(!pal) dp2[a[i][1]][a[i][len]]++;
	}
	for(int i=0;i<=mx;++i) for(int j=0;j<=mx;++j) for(int k=0;k<=mx;++k) dp3[i][j][k]=0;
	for(int i=0;i<=mx;++i) for(int j=0;j<=mx;++j) for(int k=0;k<=mx;++k) for(int z=0;z<=mx;++z)
	{
		ll tmp=(ll)dp2[i][z]*dp2[j][z]%mod*dp2[k][z]%mod;
		ADD(dp3[i][j][k],tmp);
	}
	for(int i=0;i<=mx;++i) for(int j=0;j<=mx;++j) for(int k=0;k<=mx;++k) for(int z=0;z<=mx;++z)
	{
		ll tmp=(ll)dp3[i][j][k]*dp3[i][j][z]%mod*dp3[i][k][z]%mod*dp3[j][k][z]%mod;
		ADD(sol,tmp);
	}
	/*use.clear();
	for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++)
	{
		if(dp2[i][j])
		{
			use.pb({i,j});
		}
	}
	for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++)
	{
		if(dp2[i][j])
		{
			vector<int> v;
			v.pb(i);
			v.pb(j);
			Solve(v,dp2[i][j]);
		}
	}*/
	/*for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++) for(int k=0;k<SZ;k++) for(int l=0;l<SZ;l++)
	{
        dp4[i][j][k][l]=mul(mul(dp2[i][j],dp2[k][l]),mul(dp2[i][k],dp2[j][l]));
	}
	//printf("%i\n",dp4[0][0][0][0]);
	int ans=0;
	for(int i=0;i<SZ;i++) for(int j=0;j<SZ;j++) for(int k=0;k<SZ;k++) for(int l=0;l<SZ;l++)
	for(int i2=0;i2<SZ;i2++) for(int j2=0;j2<SZ;j2++) for(int k2=0;k2<SZ;k2++) for(int l2=0;l2<SZ;l2++)
	{
		ADD(ans,mul(mul(dp4[i][j][k][l],dp4[i2][j2][k2][l2]),mul(mul(dp2[i][i2],dp2[j][j2]),mul(dp2[k][k2],dp2[l][l2]))));
	}
	return ans;*//*
}
int Get(char c)
{
	if(c>='a' && c<='z') return c-'a';
	if(c>='A' && c<='Z') return c-'A'+26;
	return c-'0'+52;
}
vector<int> all[M];
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	//scanf("%i",&n);
	cin>>n;
	vector<string> vec;
	for(int i=1;i<=n;i++)
	{
		//scanf("%s",s[i]+1);
		//int len=strlen(s[i]+1);
		string tmp;
		cin>>tmp;
		//for(int j=1;j<=len;j++) tmp+=s[i][j];
		string rev=tmp;
		reverse(rev.begin(),rev.end());
		if(tmp.compare(rev)<0) vec.pb(tmp);
		else vec.pb(rev);
		/*reverse(tmp.begin(),tmp.end());
		if(!was[tmp])
		{
			reverse(tmp.begin(),tmp.end());
			was[tmp]=1;
			for(int j=1;j<=len;j++) a[i][j]=Get(s[i][j]),mx=max(mx,a[i][j]);
			all[len].push_back(i);
		}*//*
	}
	sort(vec.begin(),vec.end());
	int sz=0;
	for(int i=1;i<n;i++) if(vec[i]!=vec[sz]) vec[++sz]=vec[i];
	for(int i=0;i<=sz;i++)
	{
		for(int j=0;j<vec[i].size();j++) a[i+1][j+1]=Get(vec[i][j]),mx=max(mx,a[i+1][j+1]);
		all[vec[i].size()].pb(i+1);
		//cout<<vec[i]<<"\n";
	}
	//int ans=0;
	for(int i=1;i<=10;i++) if(all[i].size()) Solve(i,all[i]);
	//printf("%i\n",sol);
	cout<<sol;
	return 0;
}*/