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

    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        vector<int> cnt(26);
        for(char c:s)
            cnt[c-'a']++;
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)
            cin>>b[i];
        string t(m,'_');
        while(true)
        {
            int cur=0;
            for(int i=0;i<m;i++)
                if(b[i]==0)
                    cur++,
                    b[i]=-2;
            if(!cur)
                break;
            while(cnt.back()<cur)
                cnt.pop_back();
            cnt.pop_back();
            char ch='a'+cnt.size();
            for(int i=0;i<m;i++)
                if(b[i]==-2)
                    for(int j=0;j<m;j++)
                        if(b[j]>0)
                            b[j]-=abs(i-j);
            for(int i=0;i<m;i++)
                if(b[i]==-2)
                    t[i]=ch,
                    b[i]=-1;
        }
        cout<<t<<"\n";
    }
}