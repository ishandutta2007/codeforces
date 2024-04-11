#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int pref[N],suff[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,vector<int>> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            m[a].push_back(i);
        }
        vector<vector<int>> v;
        for(auto p:m)
            v.push_back(p.y);
        int k=v.size();
        pref[0]=v[0].size();
        for(int i=1;i<k;i++)
            pref[i]=pref[i-1]+v[i].size();
        suff[k]=0;
        for(int i=k-1;i>=0;i--)
            suff[i]=suff[i+1]+v[i].size();
        int ans=n;
        for(int l=0,r=0;l<k;l++)
        {
            r=max(r,l);
            while(r+1<k&&v[r].back()<=v[r+1].front())
                r++;
            int res=(l>0?pref[l-1]:0)+suff[r+1];
            if(l>0)
                res-=lower_bound(v[l-1].begin(),v[l-1].end(),v[l].front())-v[l-1].begin();
            if(r<k-1)
                res-=v[r+1].end()-lower_bound(v[r+1].begin(),v[r+1].end(),v[r].back());
            ans=min(ans,res);
        }
//        cout<<k<<"\n";
        for(int i=0;i<k-1;i++)
        {
//            cout<<"i="<<i<<"\n";
            for(int j=0;j<v[i].size();j++)
//                cout<<i<<" "<<j<<" -> "<<n<<"-"<<(j+1)<<"-"<<(v[i+1].end()-lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j]))<<"="<<(n-(j+1)-(v[i+1].end()-lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j])))<<"\n",
                ans=min(ans,n-(j+1)-(v[i+1].end()-lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j])));
        }
        cout<<ans<<"\n";
    }
}