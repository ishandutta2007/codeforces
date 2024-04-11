#include <bits/stdc++.h>

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

    int n,t;
    string s;
    cin>>n>>t>>s;
    t-=1<<(s.back()-'a');
    s.pop_back();
    t+=1<<(s.back()-'a');
    s.pop_back();
    int cnt[60]={};
    for(char c:s)
        cnt[c-'a'+1]++,
        t+=1<<(c-'a');
    if(t<0)
        cout<<"No",exit(0);
    for(int i=0;t;i++,t>>=1)
        {
            if(t&1)
                if(!cnt[i])
                    cout<<"No",exit(0);
                else
                    cnt[i]--;
            cnt[i+1]+=cnt[i]/2;
        }
    cout<<"Yes";
}