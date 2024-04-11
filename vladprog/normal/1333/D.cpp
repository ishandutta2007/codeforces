#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>> res;
    int sum=0;
    while(true)
    {
        res.push_back(vector<int>());
        for(int i=0;i<n-1;i++)
            if(s[i]=='R'&&s[i+1]=='L')
                s[i]='L',s[i+1]='R',
                res.back().push_back(i),
                i++;
        sum+=res.back().size();
        if(res.back().empty())
        {
            res.pop_back();
            break;
        }
    }
//    cout<<res.size()<<" "<<sum<<"\n";
    if(k<res.size()||k>sum)
        cout<<-1,exit(0);
    int cur=res.size();
    for(auto&v:res)
    {
        vector<int> last;
        for(int x:v)
            if(cur<k)
                cout<<1<<" "<<x+1<<"\n",
                cur++;
            else
                last.push_back(x);
        if(!last.empty())
        {
            cout<<last.size()<<" ";
            for(int x:last)
                cout<<x+1<<" ";
            cout<<"\n";
        }
        else
            cur--;
    }
}