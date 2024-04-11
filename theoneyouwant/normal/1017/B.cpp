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
    
   int n;
   cin>>n;
   string a,b;
 cin>>a>>b;
   ll total10=0,total00=0,total01=0,total11=0;
    REP(i,n)
    {
        if(b[i]=='0')
        {
            if(a[i]=='0')
            {
                total00++;
            }
            else
            {
                total10++;
            }
        }
        else
        {
            if(a[i]=='0')
            {
                total01++;
            }
            else
            {
                total11++;
            }
        }
    }
 // cout<<total00<<" "<<total01<<" "<<total10<<" "<<total11<<endl;
    ll answer = total11*total00 + total01*total10 +total10*total00;
    cout<<answer<<endl;
     return 0;
}