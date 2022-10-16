#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
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
	long long t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int pre_p,pre_c;
		cin>>pre_p>>pre_c;
		int possible =1;
		if(pre_c>pre_p) possible=0;
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			if(a-pre_p<0) possible=0; 
			else if(b-pre_c<0) possible=0;
			else if(a-pre_p<b-pre_c) possible=0;
			pre_p=a;
			pre_c=b;
		}
		if(possible) cout<<"YES";
		else cout<<"NO";
		cout<<"\n";

	}	
}