#include<iostream>

using namespace std;

int a[1000000+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        bool can=false;
        for (int i=1; i<n; i++)
        {
            if (a[i]>=a[i-1])
            {
                can=true;
                break;
            }
        }
        if (can) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}