#include <bits/stdc++.h> 

using namespace std; 
#define int long long 
const int p=998244353;
int po(int a,int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2==0)
	{
		int u=po(a,b/2);
		return (u*u)%p;
	}
	else 
	{
		int u=po(a,b-1);
		return (a*u)%p;
	}
}
int inv(int x) {return po(x,p-2);}
int slv(vector <int> v,int n)
{
	int cnt[n+1]={0};
	for(auto h:v) cnt[h-1]++;
    int ans=1; 
    int curr=cnt[n];
    ans*=curr;
    for(int i=(n-1);i>=1;i--)
    {
      	curr--; 
    	curr+=cnt[i];
    	ans*=curr;
    	ans%=p;
    }
    int o=1;
    for(int i=1;i<=n;++i) {o*=inv(i);o%=p;}
    ans*=o;
    ans%=p;
    return ((1-ans)%p);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m; 
	vector <int> a[m];
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) {int x;cin>>x;a[j].push_back(x);}
	int ans=0;
    for(int i=0;i<m;++i) 
    {
    	ans+=slv(a[i],n);
    	ans%=p;
    }
    cout<<(ans%p+p)%p;
	return 0;
}