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
	int n;
	cin>>n;
	vector<int> v(n);
	long long sum=0;
	for(int i=0;i<n;i++) {cin>>v[i];sum+=v[i];}
	if(sum%n==0)
	{
		int t=sum/n;
		sort(v.begin(),v.end());
		long long time=0;
		for(int i=0;i<n;i++)
		{
			time+=abs(t-v[i]);
		}
		cout<<(time+1)/2;
	}	
	else
	{
		int more=sum%n;
		int less=n-sum%n;
		int t=sum/n;
		sort(v.begin(),v.end());
		long long time=0;
		for(int i=0;i<less;i++)
		{
			time+=abs(t-v[i]);
		}
		for(int i=less;i<n;i++)
		{
			time+=abs(t+1-v[i]);
		}
		cout<<(time+1)/2;
	}

}