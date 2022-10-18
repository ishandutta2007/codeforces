#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int n,a[N];
int dfs(vector<int> v,int k)
{
	if(k==-1) return 0;
	vector<int> v0,v1;
	for(int i:v)
	{
		if(i>>k&1) v1.pb(i);
		else v0.pb(i);
	}
	if(v0.size()==0) return dfs(v1,k-1);
	else if(v1.size()==0) return dfs(v0,k-1);
	else return min(dfs(v0,k-1),dfs(v1,k-1))|(1<<k);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	vector<int> v;
	for(int i=1;i<=n;i++) v.pb(read());
	cout<<dfs(v,29)<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}