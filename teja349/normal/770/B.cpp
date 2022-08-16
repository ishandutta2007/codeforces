#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define key pair<ld,ld>
#define vii vector<pair<int,int> >
#define vi vector<int>
#define vvi vector<vector<int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define nu 100001
#define M 1000000007
#define ff first
#define ss second
int main() 
{
	string s;
	string t;
	cin>>s;
	t=s;
	ll num=stoll(s);
	for(ll p=1;p<s.size();p++)
	t[p]='9';
	ll r=stoll(t);
	if(r<=num)
	{
	        cout<<t;
	        return 0;
	}
	for(ll p=s.size()-1;p>=1;p--)
	{
	    t[p]='8';
	    ll r=stoll(t);
	    if(r<=num)
	    {
	        cout<<t;
	        return 0;
	    }
	    t[p]='9';
	}
	if(t[0]=='1')
	{
	    t=t.substr(1,t.size()-1);
	    cout<<t;
	}
	else
	{
	    ll tr=t[0]-'0';
	    tr--;
	    cout<<tr;
	    t=t.substr(1,t.size()-1);
	    cout<<t;
	    return 0;
	}
}