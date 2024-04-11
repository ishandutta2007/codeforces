
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
    
    long long int n;
    cin>>n;
    if(n<15)
    {
    bool a[50*n+1]={0};
    a[1]=1;
    a[5]=1;
    a[10]=1;
    a[50]=1;
bool b[50*n+1]={0};

    for(int j=1;j<n;j++)
    {
        for(int i=1;i<=50*(n-1)+1;i++)
        {
            if(a[i]==1)
            {
                b[i+1]=1;
                b[i+5]=1;
                b[i+10]=1;
                b[i+50]=1;
            }
        }
        for(int i=1;i<=50*n;i++)
        {
            a[i]=b[i];
b[i]=0;
            
        }
    }
    long long int total=0;
    for(int i=1;i<50*n+1;i++)
    {
        if(a[i]==1)
        {
            total++;
        }
    }
    cout<<total;
    }
    else
    {
        cout<<49*n-247;
    }
}