#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int main()
{
    int n;
    string s;
    cin>>n>>s;
    string t = s;
    vector<int> v;
    for(int i=0;i<s.size()-1;++i)
    {
        if(t[i] == 'B')
        {
            v.push_back(i);
            t[i] = 'W';
            if(t[i+1]=='W') t[i+1]='B';
            else t[i+1]='W';
        }
    }
    if(t.back() == 'W')
    {
        cout<<v.size()<<endl;
        for(int i:v) cout<<1+i<<" ";cout<<endl;
        return 0;
    }
    v.clear();
    t = s;
    for(int i=0;i<s.size()-1;++i)
    {
        if(t[i] == 'W')
        {
            v.push_back(i);
            t[i] = 'B';
            if(t[i+1]=='W') t[i+1]='B';
            else t[i+1]='W';
        }
    }
    if(t.back() == 'B')
    {
        cout<<v.size()<<endl;
        for(int i:v) cout<<i+1<<" ";cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
}