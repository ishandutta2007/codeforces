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
    
    int n,b;
    cin>>n>>b;
    int a[n],oe[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            if(a[i]%2==1)
            {
                oe[0]=1;
            }
            else
            {
                oe[0]=-1;
            }
            continue;
        }
        if(a[i]%2==1)
        {
            oe[i]=oe[i-1]+1;
        }
        else
        {
            oe[i]=oe[i-1]-1;
        }
    }
    vector<int> v;
    for(int i=1;i<n-1;i++)
    {
        if(oe[i]==0)
        {
            v.push_back(abs(a[i+1]-a[i]));
        }
    }
    sort(v.begin(),v.end());
    long long int total=0,number=0;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        if(total+(*it)<=b)
        {
            
            total+=(*it);
            number++;
        }
        else
        {
            break;
        }
    }
    cout<<number;
     return 0;
}