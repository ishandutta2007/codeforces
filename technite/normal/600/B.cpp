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
	int a,b;
	cin>>a>>b;
	vector<int> v1(a),v2(b);
	for(int i=0;i<a;i++) cin>>v1[i];
	for(int i=0;i<b;i++) cin>>v2[i];
	sort(v1.begin(),v1.end());
	for(int i=0;i<b;i++)
	{
		auto it=upper_bound(v1.begin(),v1.end(),v2[i]);
		int t=it-v1.begin();
		cout<<t<<" ";
	}	
}