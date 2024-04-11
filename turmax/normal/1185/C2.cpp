#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <int> a(n);
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        a[i]=k;
    }
    set <int> curr;
    map <int,int> coun;
    int sumcurr=0;
    int x;
    vector <int> currdel;
    int res;
    int currres=0;
    for(int i=0;i<n;++i)
    {
        res=0;
        currdel.clear();
        x=a[i];
        if((sumcurr+x)<=m)
        {
            cout<<currres<<" ";
        }
        else
        {
            while((sumcurr+x)>m)
            {
                ++res;
                sumcurr+=(*curr.begin());
                currdel.push_back((*curr.begin()));
                coun[(*curr.begin())]--;
                if(coun[(*curr.begin())]==0)
                {
                    curr.erase(*curr.begin());
                }
            }
            cout<<currres+res<<" ";
        }
        currdel.push_back(-x);
        sort(currdel.begin(),currdel.end());
        reverse(currdel.begin(),currdel.end());
        currres+=currdel.size();
        for(int i=0;i<currdel.size();++i)
        {
            if((sumcurr-currdel[i])<=m)
            {
                sumcurr-=currdel[i];
                curr.insert(currdel[i]);
                coun[currdel[i]]++;
                currres--;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}