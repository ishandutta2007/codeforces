#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
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
void printvector(vector<ll>&v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n]={0};
			int l=0;
			int mid;
			int r=n-1;
			set<pair<int,int>> s;
			s.insert({n,0});
			int i=1;
			while(s.size()!=0)
			{
				auto it1=s.end();
				it1--;
				auto j=*it1;
				auto it=s.lower_bound({j.first,0});
				j=*it;
				//cout<<j.first<<" "<<j.second<<"\n";
				l=j.second;
				r=j.second+j.first-1;
				if(j.first==0) break;
				if((j.first)%2==0)
				{
					mid=(l+r-1)/2;
					//cout<<i<<endl;
					a[mid]=i;
					s.erase(it);
					if((j.first/2)-1>0)
					s.insert({(j.first/2)-1,l});
					s.insert({j.first/2,mid+1});
				}
				else
				{
					mid=(l+r)/2;
					a[mid]=i;
					s.erase(it);
					if(j.first!=1)
					{
						int sz=j.first/2;
						s.insert({sz,l});
						s.insert({sz,mid+1});
					}
				}
				i++;	
			} 

		
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<"\n";
		
	}
}