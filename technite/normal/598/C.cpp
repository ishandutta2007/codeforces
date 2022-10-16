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
int main()
{
	int n,a,b;
	vector<pair<long double,int> > v;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(atan2(y,x),i+1));
	}
	long double mn=1000000000;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		long double t=v[(i+1)%n].first-v[i].first;
		if(t<0) t+=2*acos(-1);
		if(t<mn){
			mn=t;
			a=v[i].second;
			b=v[(i+1)%n].second;
		}
	}
	cout<<a<<" "<<b<<endl;
}