#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(char c) {return c=='i'||c=='e'||c=='a'||c=='o'||c=='u';}
string ss[100005];
vector<int> v[1000005][5];
int vis[1000005];
int a[200];
vector<pair<int,int>> v1,v2;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    a['a']=0,a['e']=1,a['i']=2,a['o']=3,a['u']=4;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int mc=0;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        ss[i] = s;
        int cnt=0;
        char last=0;
        for(int i=0;i<s.size();++i) if(check(s[i])) cnt++, last=s[i];
        v[cnt][a[last]].push_back(i);
        mc=max(mc,cnt);
        vis[cnt]=1;
    }
    int dif=0,sam=0;
    for(int i=1;i<=mc;++i)
    {
        if(!vis[i]) continue;
        int cnt1=0,cnt2=0;
        for(int j=0;j<5;++j)
        {
            cnt1+=v[i][j].size()/2,
            cnt2+=v[i][j].size()&1;
        }
        sam+=cnt1,dif+=cnt2/2;
    }
    int ans1=0;
    if(dif>=sam) ans1=sam;
    else ans1=(dif+sam)/2;
    cout<<ans1<<endl;
    for(int i=1;i<=mc;++i)
    {
        if(!vis[i]) continue;
        int tmp1=0;
        for(int j=0;j<5;++j)
        {
            int k=0;
            while(v1.size()<ans1)
            {
                if(k+1<v[i][j].size())
                {
                    v1.push_back({v[i][j][k],v[i][j][k+1]});
                    k+=2;
                }
                else break;
            }
            for(;k<v[i][j].size();++k)
            {
                if(!tmp1) tmp1=v[i][j][k];
                else
                {
                    v2.push_back({tmp1,v[i][j][k]});
                    tmp1=0;
                }
            }
        }
    }
    for(int i=0;i<ans1;++i)
    {
        cout<<ss[v2[i].first]<<" "<<ss[v1[i].first]<<"\n"<<ss[v2[i].second]<<" "<<ss[v1[i].second]<<"\n";
    }
}