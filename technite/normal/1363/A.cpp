//template start//
#include<bits/stdc++.h>
using namespace std;
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
int main()
{
    TT
    {
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        int odd=0,even=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]%2) odd++;
            else even++;
        }
        if(!odd)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
                if(x>=odd)
                {
                    int eve=max(x-(odd%2?odd:odd-1),0);
                    if(eve<=even) cout<<"YES"<<"\n";
                    else cout<<"NO"<<'\n';
                }
                else
                {
                    if(x%2==0)
                    {
                        if(even) cout<<"YES";
                        else cout<<"NO";
                    }
                    else cout<<"YES";
                    cout<<"\n";
                }
        }
    }
}