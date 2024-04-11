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

long long int answer (string a,string b, int n)
{
    if(n<=2)
    {
        if(n==0 || n==1)
        {
            return 0;
        }
        else
        {
            if(a[1]=='X' && b[1]=='X')
            {
                return 0;
            }
            if(a[1]=='0' && b[1]=='0')
            {
                if(a[0]=='0' || b[0]=='0')
                {
                    return 1;
                }
                else
                {
                return 0;
                }
            }
            else
            {
                if(a[0]=='0' && b[0]=='0')
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    
    if(a[n-1]=='X' && b[n-1]=='X')
    {
        return answer(a,b,n-1);
    }
    if(a[n-1]=='0' && b[n-1] =='0')
    {
        if(a[n-2]=='0' && b[n-2]=='0')
        {
            if(n>=3 && a[n-3]=='0' && b[n-3]=='0')
            {
                return 2+answer(a,b,n-3);
            }
            else
            {
                return 1+answer(a,b,n-2);
            }
        }
        if(a[n-2]=='0' || b[n-2]=='0')
        {
            return 1+answer(a,b,n-2);
        }
        else
        {
        return answer(a,b,n-2);
        }
    }
    if(a[n-1]=='0' || b[n-1]=='0')
    {
        if(a[n-2]=='0' && b[n-2]=='0')
        {
            return 1+answer(a,b,n-2);
        }
        else
        {
            return answer(a,b,n-1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a;
    cin>>b;
    int n=a.length();
    cout<<answer(a,b,n);
     return 0;
}