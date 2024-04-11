#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	int a[m+1]={0};
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a[t]++;
	}
	int ans=0,total=n;
	for(int i=1;i<=m;i++)
	{
		ans+=a[i]*(total-a[i]);
		total-=a[i];
	}
	cout<<ans;
}