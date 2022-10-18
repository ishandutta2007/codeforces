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

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        k++;
        string s;
        cin>>s;
        s+='1';
        vector<int> v;
        int cur=0;
        for(char c:s)
            if(c=='0')
                cur++;
            else
                v.push_back(cur),
                cur=0;
//        for(int x:v)
//            cout<<x<<" ";
//        cout<<"-> ";
        int ans=0;
        for(int i=0;i<v.size();i++)
            if(i==0&&i==v.size()-1)
                ans+=(v[i]+k-1)/k;
            else if(i==0||i==v.size()-1)
                ans+=v[i]/k;
            else
                ans+=(v[i]-k+1)/k;
        cout<<ans<<"\n";
    }
}