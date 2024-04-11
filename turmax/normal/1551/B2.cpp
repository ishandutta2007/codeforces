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
        int n,k;
        cin>>n>>k;
        pair <int,int> a[n];
        for(int i=0;i<n;++i) {cin>>a[i].first;a[i].second=i;}
        sort(a,a+n);
        int lst[k];int c[n]={0};
        for(int i=0;i<k;++i) lst[i]=(-1);
        int curr=0;
        int val=0;
        vector <int> v;
        for(int i=0;i<n;++i)
        {
            if(lst[curr]==a[i].first)
            {
                continue;
            }
            else
            {
                lst[curr]=a[i].first;
                c[a[i].second]=curr+1;
                v.push_back(a[i].second);
                ++curr;
                curr%=k;
                if(curr==0) ++val;
            }
        }
        while((v.size()%k)!=0)
        {
            int i=v.back();
            c[i]=0;
            v.pop_back();
        }
        for(int i=0;i<n;++i) cout<<c[i]<<' ';
        cout<<endl;
    }
    return 0;
}