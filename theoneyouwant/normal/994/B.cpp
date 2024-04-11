/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n>>k;
    map<int,int> m;
    long long int p[n],j[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        j[i]=p[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        m[p[i]]=x;
    }
    sort(j,j+n);
    long long int cost[n];
    long long int price[k];
    if(n>=k && k!=0)
    {
        price[0]=0;
        cost[0]=0;
    for(int i=1;i<k;i++)
    {
        price[i]=m[j[i-1]];
        if(i==1) 
        {
            cost[1]=m[j[0]];
        }
        else
        {
            cost[i]=cost[i-1]+price[i];
        }
    }
    for(int i=k;i<n;i++)
    {
        sort(price,price+k);
        cost[i]=cost[i-1];
        if(m[j[i-1]]>price[0])
        {
            cost[i]=cost[i]+m[j[i-1]]-price[0];
            price[0]=m[j[i-1]];
        }
    }
    int z=0;
     for(int i=0;i<n;i++)
        {
        int l=0,r=n-1;
           while (l <= r)
    {
        z = l + (r-l)/2;
 
        // Check if x is present at mid
        if (j[z] == p[i])
            break;
 
        // If x greater, ignore left half
        if (j[z] < p[i])
            l = z + 1;
 
        // If x is smaller, ignore right half
        else
            r = z - 1;
    }
    cout<<cost[z]+m[p[i]]<<" ";
        }
    }
    else if (k==0)
    {
        for(int i=0;i<n;i++)
        {
            cout<<m[p[i]]<<" ";
        }
    }

     return 0;
}