#include <bits/stdc++.h>

using namespace std;
#define int long long
string s1;
vector <int> res;
void go(int x)
{
    //cout<<x<<" x "<<endl;
    res.push_back(x);
    for(int i=0;i<x;++i)
    {
        s1[i]=('1'-s1[i]+'0');
    }
    reverse(s1.begin(),s1.begin()+x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    res.clear();
    int n;
    cin>>n;
    string s2;
    cin>>s1>>s2;
    int r=(n-1);
    while(r>=0)
    {
        if(s2[r]==s1[0])
        {
            go(1);
            go(r+1);
        }
        else
        {
            go(r+1);
        }
        r--;
    }
    cout<<res.size()<<' ';
    for(auto v:res)
    {
        cout<<(v)<<' ';
    }
    cout<<endl;
    }
    return 0;
}