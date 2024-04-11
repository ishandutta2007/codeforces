#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int t;
//    cin>>t;
//    while(t--)
    {
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        s="___"+s+"___";
        int cnt=0;
//        cout<<s.size()<<endl;
        for(int i=0;i+3<=s.size();i++)
            if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
                cnt++;
        while(q--)
        {
            int pos;
            char c;
            cin>>pos>>c;
            pos+=2;
            for(int i=pos-2;i<=pos;i++)
                if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
                    cnt--;
            s[pos]=c;
            for(int i=pos-2;i<=pos;i++)
                if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
                    cnt++;
            cout<<cnt<<"\n";
        }
    }
}