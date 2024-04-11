#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    multiset<string> in;
    while(n--)
    {
        string s;
        cin>>s;
        in.insert(s);
    }
    string lef,mid;
    while(!in.empty())
    {
        string s=*in.begin();
        in.erase(in.begin());
        string r;
        reverse_copy(s.begin(),s.end(),back_inserter(r));
        if(in.find(r)!=in.end())
            lef+=s,
            in.erase(in.find(r));
        else if(r==s)
            mid=s;
    }
    string rig;
    reverse_copy(lef.begin(),lef.end(),back_inserter(rig));
    cout<<lef.size()+mid.size()+rig.size()<<"\n"<<lef<<mid<<rig;
}