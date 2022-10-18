#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k%3)
            cout<<(n%3?"Alice\n":"Bob\n");
        else
        {
            n%=(k+1);
            cout<<(n%3||n==k?"Alice\n":"Bob\n");
        }
    }
}