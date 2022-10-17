#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt1=0,cnt2=0;
    for(int i=0;i<s.size();++i) if(s[i]=='(') ++cnt1;else ++cnt2;
    if(cnt1!=cnt2) return cout<<"No"<<endl,0;
    int mx=111,cur=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(') cur++;
        else cur--;
        mx=min(mx,cur);
    }
    if(mx<-1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}