#include <bits/stdc++.h>

using namespace std;
#define int long long
bool a[1000000];
bool used[1000000];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> c;
    int curr=0;
    int l=0;
    for(int i=0;i<1000000;++i)
    {
        a[i]=false;
    }
    vector <int> ans;
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        if(k<0)
        {
            ++k;
            k=(-k);
            if(!a[k])
            {
                cout<<(-1);
                return 0;
            }
            else
            {
                a[k]=false;
                curr--;
            }
        }
        else
        {
            k--;
            c.push_back(k);
            if(used[k])
            {
                cout<<(-1);
                return 0;
            }
            if(a[k])
            {
                cout<<(-1);
                return 0;
            }
            else
            {
                a[k]=true;
                ++curr;
            }
            used[k]=true;
        }
        if(curr==0)
        {
            ans.push_back(i-l+1);
            l=(i+1);
            for(int j=0;j<c.size();++j)
            {
                used[c[j]]=false;
            }
        }
    }
    if(curr!=0)
    {
        cout<<(-1);
        return 0;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}