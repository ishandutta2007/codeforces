#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int curr=0;
        while(true)
        {
            ++curr;
            int ans1=curr*(curr+1)/2;
            if(curr>=3 && (ans1-2)>=x)
            {
                cout<<curr<<endl;
                break;
            }
            else if(x==ans1 || (curr==2 && x==1) || (curr==1 && x==1))
            {
                cout<<curr<<endl;
                break;
            }
        }
    }
    return 0;
}