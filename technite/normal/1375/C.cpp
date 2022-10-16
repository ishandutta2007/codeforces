#include<bits/stdc++.h>
using namespace std;
int mx[]={1,-1,0,0};
int my[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        if(v[0]<v[n-1]) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}