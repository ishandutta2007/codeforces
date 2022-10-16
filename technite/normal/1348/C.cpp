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
	int t,n,k;
	cin>>t;
	while(t--){
		int n,k;
		string s;
		cin>>n>>k>>s;
		sort(s.begin(),s.end());
		if(s[0]!=s[k-1]){
			cout<<s[k-1]<<endl;
			continue;
		}
		cout<<s[0];
		if(s[k]!=s[n-1])
			for(int i=k;i<n;i++) cout<<s[i];
		else  
			{
				float a=((float)(n-k)/(float)k);
				cout<<s.substr(k,ceil(a));
			}
		cout<<endl;
	
}
}