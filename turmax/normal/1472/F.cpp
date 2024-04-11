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
        int n,m;
        cin>>n>>m;
        vector <pair<int,int> > v(m);
        vector <int> mom;
        mom.push_back(0);mom.push_back(1);mom.push_back(n);mom.push_back(n+1);
        for(int i=0;i<m;++i)
        {
            cin>>v[i].second>>v[i].first;
            v[i].second--;
            mom.push_back(v[i].first-1);
            mom.push_back(v[i].first);
            mom.push_back(v[i].first+1);
            mom.push_back(v[i].first+2);
            if((v[i].first%2)==1)
            {
                mom.push_back(v[i].first-2);
                mom.push_back(v[i].first+3);
            }
        }
        sort(mom.begin(),mom.end());mom.erase(unique(mom.begin(),mom.end()),mom.end());
        map <int,int> o;
        for(int i=0;i<mom.size();++i) o[mom[i]]=i;
        v.push_back({0,0});
        v.push_back({0,1});
        v.push_back({n+1,0});
        v.push_back({n+1,1});
        sort(v.begin(),v.end());
        bool ok[mom.size()][2];
        for(int i=0;i<mom.size();++i)
        {
            ok[i][0]=true;
            ok[i][1]=true;
        }
        for(auto h:v) ok[o[h.first]][h.second]=false;
        bool h=true;
        //for(int j=0;j<2;++j) {for(int i=0;i<mom.size();++i) if(ok[i][j]) cout<<'.'; else cout<<'*'; cout<<endl;}
        for(int i=0;i<mom.size();++i)
        {
            if(!ok[i][0] && !ok[i][1])
            {
                continue;
            }
            if(ok[i][0] && ok[i][1])
            {
                if(i==(mom.size()-1))
                {
                    break;
                }
                continue;
            }
            if(ok[i][0] && !ok[i][1])
            {
                if(i==(mom.size()-1))
                {
                    h=false;
                    break;
                }
                if(ok[i+1][0])
                {
                    ok[i+1][0]=false;
                }
                else
                {
                    h=false;
                    break;
                }
            }
            if(!ok[i][0] && ok[i][1])
            {
                if(i==(mom.size()-1))
                {
                    h=false;
                    break;
                }
                if(ok[i+1][1])
                {
                    ok[i+1][1]=false;
                }
                else
                {
                    h=false;
                    break;
                }
            }
        }
        if(h) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}