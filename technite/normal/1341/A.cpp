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
	fast;
	int t;
	cin >> t;
	while(t--)
	{
	    int n,a,b,c,d;
		cin >> n>> a>>b>>c>>d;
		if((a-b)*n<=(c+d) && (a+b)*n>=(c-d))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}