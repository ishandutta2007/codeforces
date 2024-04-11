
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while (n--) {
        string s1,s2;
        cin>>s1>>s2;
        vector<pair<char,int> > v1,v2;
        char lst=s1[0];
        int cnt=0;
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]==lst) cnt++;
            else
            {
                v1.push_back({lst,cnt});
                cnt=1;
            }
            lst = s1[i];
        }
        v1.push_back({lst,cnt});
        lst=s2[0];
        cnt=0;
        for(int i=0;i<s2.size();++i)
        {
            if(s2[i]==lst) cnt++;
            else
            {
                v2.push_back({lst,cnt});
                cnt=1;
            }
            lst = s2[i];
        }
        v2.push_back({lst,cnt});
        if(v1.size() != v2.size())
        {
            cout<<"NO"<<endl;
            continue;
        }
        int ok = 1;
        for(int i=0;i<v1.size();++i)
        {
            if(v1[i].first != v2[i].first || v1[i].second > v2[i].second)
            {
                ok = 0;
                break;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}