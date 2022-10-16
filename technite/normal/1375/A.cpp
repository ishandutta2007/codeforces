#include<bits/stdc++.h>
using namespace std;
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
        for(int i=0;i<n;i++) 
        {
            cin>>v[i];
            if(i%2)
                v[i]=-abs(v[i]);
            else
                v[i]=abs(v[i]);
        }
        for(auto x:v) cout<<x<<" ";
            cout<<'\n';

    }
}