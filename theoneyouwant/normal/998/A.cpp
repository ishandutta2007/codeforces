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
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int a[n],sum=0;
    map <int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=i+1;
        sum+=a[i];
    }
    sort(a,a+n);
    if(n==1)
    {
        cout<<"-1";
    }
    else
    {
        if(sum-a[0]==a[0])
        {
            cout<<"-1";
        }
        else
        {
            cout<<"1"<<endl;
            cout<<m[a[0]];
        }
    }
     return 0;
}