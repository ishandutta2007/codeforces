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
    
   	int t;
   	cin>>t;
   	for(int i=0;i<t;i++)
   	{
   		int n;
   		cin>>n;
   		int a[n];
   		vector<int> v;
   		map<int,int> m;
   		for(int j=0;j<n;j++)
   			{
   				cin>>a[j];
   				if(m[a[j]]==1)
   				{
   					m[a[j]]=0;
   					v.PB(a[j]);
   					//cout<<"pushed here "<<a[j]<<endl;
   				}
   				else
   				{
   					m[a[j]]++;
   				}
   			}
   		sort(v.begin(),v.end());
   		long double most=1e18;
   		int side1=0,side2=0;
   		vector<int>::iterator it2 = v.begin();
   		it2++;
   		for(vector<int>::iterator it=v.begin();it!=v.end();it++)
   		{
                        if(it2==v.end())break;
   			long double x1=*it,x2=*it2;
   			if((x1/x2 + x2/x1)<=most)
   			{
   				side1=x1;
   				side2=x2;
   				most=x1/x2+x2/x1;
   			}
                        it2++;
   		}
   		cout<<side1<<" "<<side1<<" "<<side2<<" "<<side2<<endl;

   	}
    
     return 0;
}