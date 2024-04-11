#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
int cnt1;
int cnt;
int ans;
int sh;
int x,y;
void ch(int i)
{
    int sh1,sh2;
    //cout<<i<<" i "<<endl;
    //cout<<sh<<" sh "<<endl;
    //cout<<cnt1<<" cnt1 "<<endl;
    //cout<<cnt<<" cnt "<<endl;
    if(s[i]=='0')
    {
    sh1=(cnt*y+(cnt1-cnt)*x);
    sh2=((i-cnt)*x+(s.size()-i-1-(cnt1-cnt))*y);
    }
    else
    {
    sh2=(cnt*y+(cnt1-cnt-1)*x);
    sh1=((i-cnt)*x+(s.size()-i-1-(cnt1-cnt-1))*y);
    }
    sh+=(2*sh2);
    sh-=(2*sh1);
    if(s[i]=='1') cnt1--;
    else cnt1++;
    s[i]=('0'+('1'-s[i]));
    ans=min(ans,sh);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    cin>>x>>y;
    vector <int> v;
    bool ok[s.size()]={0};
    for(int i=0;i<s.size();++i) if(s[i]=='?') {ok[i]=1;s[i]='0';v.push_back(i);}
    sh=0;
    for(int i=0;i<s.size();++i) if(s[i]=='1') cnt1++;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='0')
        {
             sh+=(cnt*y+(cnt1-cnt)*x);
        }
        else
        {
             sh+=((i-cnt)*x+(s.size()-i-1-(cnt1-cnt-1))*y);
        }
        //cout<<i<<" i "<<sh<<" sh "<<endl;
        if(s[i]=='1') ++cnt;
    }
    //cout<<s<<" s "<<endl;
    //cout<<sh<<" sh "<<endl;
    ans=sh;
    cnt=0;
    for(int i=0;i<s.size();++i)
    {
        if(ok[i])
        ch(i);
        if(s[i]=='1') ++cnt;
    }
    //cout<<ans<<" ans "<<endl;
    for(auto h:v) s[h]='1';
    sh=0;
    cnt1=0;
    for(int i=0;i<s.size();++i) if(s[i]=='1') cnt1++;
    cnt=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='0')
        {
             sh+=(cnt*y+(cnt1-cnt)*x);
        }
        else
        {
             sh+=((i-cnt)*x+(s.size()-i-1-(cnt1-cnt-1))*y);
        }
        if(s[i]=='1') ++cnt;
    }
    //cout<<s<<" s "<<endl;
    ans=min(ans,sh);
    cnt=0;
    for(int i=0;i<s.size();++i)
    {
        if(ok[i])
        ch(i);
        if(s[i]=='1') ++cnt;
    }
    cout<<ans/2;
    return 0;
}