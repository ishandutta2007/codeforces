#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t,m,z,p,v;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        vector <vector<int> > a;
        cin>>t;
        p=0;
        vector <int> ans(t);
        for(int j=0;j<t;++j)
        {
            cin>>m>>z;
            vector <int> f;
            f.push_back(m);
            f.push_back(z);
            f.push_back(j);
            a.push_back(f);
        }
        sort(a.begin(),a.end());
        v=(-1);
        for(int j=0;j<(t-1);++j)
        {
            v=max(v,a[j][1]);
            if(v<a[j+1][0])
            {
                for(int k=0;k<=j;++k)
                {
                    ans[a[k][2]]=1;
                }
                for(int k=(j+1);k<t;++k)
                {
                    ans[a[k][2]]=2;
                }
                for(int h3=0;h3<ans.size();++h3)
                {
                    cout<<ans[h3]<<" ";
                }
                p=1;
                break;
            }
        }
        if(p==0)
        {
            cout<<(-1);
        }
        cout<<""<<endl;
    }
    return 0;
}