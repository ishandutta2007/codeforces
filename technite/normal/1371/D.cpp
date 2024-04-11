#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> v(n,vector<int>(n,0));
        int i=0;
        int cnt=0;
        if(k==0)
        {
            cout<<0<<'\n';
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<v[i][j];
                }
                cout<<'\n';
            }
            continue;
        }
        while(cnt<k)
        {
            for(int j=0,l=i;l<n&&cnt<k;j++,l++)
            {
                v[j][l]=1;
                cnt++;
            }
            for(int j=n-i,l=0;l<i&&cnt<k;j++,l++)
            {
                v[j][l]=1;
                cnt++;
                
            }
            i++;
        }
    
        if(k%n==0) cout<<0<<'\n';
        else cout<<2<<'\n';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<v[i][j];
            }
            cout<<'\n';
        }
    }
}