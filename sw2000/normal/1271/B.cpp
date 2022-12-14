#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e3+10;
const ll mod=1e9+7;
string s;

void turn(int i)
{
    if(s[i]=='B')s[i]='W';
    else s[i]='B';
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n,cnt[2]={0};
    vector<int>ans;
    cin>>n>>s;
    for(auto i:s)
    {
        if(i=='B')cnt[0]++;
        else cnt[1]++;
    }
    if((cnt[1]&1)&&(cnt[0]&1))
    {
        cout<<-1;
        return 0;
    }
    if(cnt[0]%2==0)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='B')
            {
                ans.push_back(i+1);
                turn(i);
                turn(i+1);
            }
        }
    }
    else if(cnt[1]%2==0)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='W')
            {
                ans.push_back(i+1);
                turn(i);
                turn(i+1);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
    return 0;
}