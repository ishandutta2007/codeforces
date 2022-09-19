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
    int n;
    cin>>n;
    n--;
    int curr=1;
    vector <int> v;
    while(true)
    {
        //cout<<n<<" "<<curr<<endl;
        if(n>=4*curr)
        {
            v.push_back(curr);
            curr*=2;
            n-=curr;
        }
        else if(n>2*curr)
        {
            v.push_back((n/2)-curr);
            v.push_back(n-(n/2)-(n/2));
            break;
        }
        else
        {
            v.push_back(n-curr);
            break;
        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}