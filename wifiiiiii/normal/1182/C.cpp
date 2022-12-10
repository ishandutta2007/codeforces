
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;


inline int isv(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int f[200];
string a[100005];
vector<int> v[1000006][7];
vector<int> ans1,ans2;
int main()
{
    f['a']=1,f['e']=2,f['i']=3,f['o']=4,f['u']=5;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int mx=1e9,Mx=0;
    rep(i,n)
    {
        cin>>a[i];
        int cnt=0, lst=0;
        for(int j=0;j<a[i].size();++j)
            if(isv(a[i][j])) cnt++,lst=a[i][j];
        v[cnt][f[lst]].push_back(i);
        mx=min(mx,cnt), Mx=max(Mx,cnt);
    }
    for(int i=mx;i<=Mx;++i)
    {
        for(int j=1;j<=5;++j)
        {
            if(v[i][j].empty()) continue;
            int n = 0;
            while(n+1<v[i][j].size())
            {
                ans2.push_back(v[i][j][n+1]);
                ans2.push_back(v[i][j][n]);
                n+=2;
            }
            while(n<v[i][j].size())
            {
                ans1.push_back(v[i][j][n]);
                n++;
            }
        }
        if(ans1.size() & 1) ans1.pop_back();
    }
    int m1=ans1.size()/2,m2=ans2.size()/2;
    int m=0;
    if(m2<=m1) m=m2;
    else m=(m1+m2)/2;
    cout<<m<<endl;
    int now1=0,now2=0;
    for(int i=0;i<m;++i)
    {
        if(now1+1<ans1.size())
        {
            cout<<a[ans1[now1]]<<" "<<a[ans2[now2]]<<endl;
            cout<<a[ans1[now1+1]]<<" "<<a[ans2[now2+1]]<<endl;
            now1+=2,now2+=2;
        }
        else
        {
            cout<<a[ans2[now2+2]]<<" "<<a[ans2[now2]]<<endl;
            cout<<a[ans2[now2+3]]<<" "<<a[ans2[now2+1]]<<endl;
            now2+=4;
        }
    }
}