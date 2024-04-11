#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

vector<int> ab,ba;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(s1[i]==s2[i]) continue;
        if(s1[i]=='a' && s2[i]=='b') ab.push_back(1+i);
        else ba.push_back(1+i);
    }
    if( (ba.size() + ab.size()) % 2)
    {
        cout << -1 << endl;
        return 0;
    }
    if( ba.size() % 2 == 0 && ab.size() % 2 == 0 )
    {
        cout << ba.size() / 2 + ab.size() / 2 << endl;
        for(int i=0;i+1<ba.size();i+=2) cout << ba[i] << " " << ba[i+1] << endl;
        for(int i=0;i+1<ab.size();i+=2) cout << ab[i] << " " << ab[i+1] << endl;
    }
    else
    {
        cout << ba.size() / 2 + ab.size() / 2 + 2 << endl;
        for(int i=0;i+1<ba.size();i+=2) cout << ba[i] << " " << ba[i+1] << endl;
        for(int i=0;i+1<ab.size();i+=2) cout << ab[i] << " " << ab[i+1] << endl;
        int t1 = ba.back(), t2 = ab.back();
        cout << t1 << " " << t1 << endl;
        cout << t1 << " " << t2 << endl;
    }
}