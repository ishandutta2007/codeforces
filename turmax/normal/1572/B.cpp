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
        vector <int> a(n);
        int s=0;
        for(int i=0;i<n;++i) {cin>>a[i];s^=a[i];}
        if(s==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int curr=0;
        vector <int> ans;
        vector <int> res;
        bool ok=true;
        while(true)
        {
            if(curr>(n-4))
            {
                assert(curr<=(n-2));
                if(curr==(n-3))
                {
                    if((a[curr]^a[curr+1]^a[curr+2])==0)
                    {
                        ans.push_back(curr);
                        break;
                    }
                    else
                    {
                        ok=false;
                        break;
                    }
                }
                else if(curr==(n-2))
                {
                    if(a[curr]==0 && a[curr+1]==0)
                    {
                        break;
                    }
                    else
                    {
                        ok=false;
                        break;
                    }
                }
            }
            else
            {
                if(a[curr]==1 && a[curr+1]==1)
                {
                    res.push_back(curr);
                    curr+=2;
                    continue;
                }
                else if(a[curr]==0 && a[curr+1]==0)
                {
                    ++curr;
                }
                else if(a[curr]==1 && a[curr+1]==0)
                {
                    if(a[curr+2]==1)
                    {
                        ans.push_back(curr);
                        a[curr]=0;a[curr+2]=0;
                        ++curr;
                        continue;
                    }
                    else
                    {
                        ans.push_back(curr);
                        res.push_back(curr);
                        a[curr+1]=1;a[curr+2]=1;
                        curr+=2;
                        continue;
                    }
                }
                else if(a[curr]==0 && a[curr+1]==1)
                {
                    if(a[curr+2]==1)
                    {
                        ans.push_back(curr);
                        a[curr+1]=0;a[curr+2]=0;
                        ++curr;
                        continue;
                    }
                    else
                    {
                        if(a[curr+3]==1)
                        {
                            ans.push_back(curr+1);
                            a[curr+1]=0;
                            a[curr+3]=0;
                            ++curr;
                            continue;
                        }
                        else
                        {
                            ans.push_back(curr+1);ans.push_back(curr);
                            a[curr]=0;a[curr+1]=0;a[curr+2]=0;a[curr+3]=1;
                            ++curr;
                        }
                    }
                }
                else {assert(false);}
            }
        }
        if(!ok) {cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        cout<<ans.size()+res.size()<<endl;
        for(auto h:ans) cout<<h+1<<' ';
        reverse(res.begin(),res.end());
        for(auto h:res) cout<<h+1<<' ';
        cout<<endl;
    }
    return 0;
}