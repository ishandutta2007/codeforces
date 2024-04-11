/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
const long double epsilon = 1e-9;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   	int n,k=0;
   	cin>>n;
   	set<char> mset;
   	string s;
   	cin>>s;
//cout<<n<<s<<endl;
   	for(int i=0;i<s.length();i++)
   	{
   		if(mset.count(s[i])!=0)
   		{
//cout<<"Hi";
   			k=1;
   			break;
   		}
   		else
   		{
   			mset.insert(s[i]);
   		}

   	}
    if(k==0 && n!=1)
    {
    	cout<<"No";
    }
    else
    {
    	cout<<"Yes";
    }
    	
     return 0;
}