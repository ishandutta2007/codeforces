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
	int n,b;
	cin>>n>>b;
	int a[n];
	int v[n]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int sz=0;
	v[0]=1;
	for(int i=1;i<n;i++)
	{
	    if(a[i]!=a[i-1])sz++;
	    v[sz]++;
	}
	
	int c=pow(2,min(19,(int)8*b/n));
	if(c>=sz+1) cout<<0;
	else
	{
	    int ans=0,answer=0;
	    int i=0,j=0;
	    for(j=0;j<sz+1;j++)
	    {
	        ans+=v[j];
	        if(j+1>c){ans=ans-v[i];i++;}
	        answer=max(ans,answer);
	        
	    }
	    cout<<n-answer;
	}
	
}