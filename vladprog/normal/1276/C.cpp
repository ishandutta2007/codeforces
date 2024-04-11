#include<bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[x]++;
    }
    vector<pair<int,int>> v;
    for(auto pr:m)
        v.emplace_back(pr.second,pr.first);
    sort(v.begin(),v.end());
//    for(auto pr:v)
//        cout<<pr.first<<" "<<pr.second<<"\n";
    int best_area=0,best_p=0;
    for(int p=1,ind=-1,sum=0;p<=n;p++)
    {
        while(ind+1<v.size()&&v[ind+1].first<=p)
            ind++,sum+=v[ind].first;
        int q=(sum+(v.size()-ind-1)*p)/p;
        if(q>=p&&p*q>=best_area)
            best_area=p*q,
            best_p=p;
    }
    int p=best_p,q=best_area/best_p;
    cout<<p*q<<"\n"<<p<<" "<<q<<"\n";
    vector<int> nums;
    for(auto pr:v)
        for(int _=0;_<min(p,pr.first);_++)
            nums.push_back(pr.second);
    reverse(nums.begin(),nums.end());
    vector<vector<int>>table(p,vector<int>(q));
    for(int i=0,j=0;j<q;j++)
        for(int k=0;k<p;k++,i++)
            table[k][(j+k)%q]=nums[i];
    for(auto row:table)
    {
        for(int x:row)
            cout<<x<<" ";
        cout<<"\n";
    }
}