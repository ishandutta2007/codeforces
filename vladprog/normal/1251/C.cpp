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

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string s0,s1;
        for(char c:s)
            if(c%2)
                s1+=c;
            else
                s0+=c;
        s0+='9'+1;
        s1+='9'+1;
        for(int i=0,j=0;i<s0.size()-1||j<s1.size()-1;)
            if(s0[i]<s1[j])
                cout<<s0[i++];
            else
                cout<<s1[j++];
        cout<<"\n";
    }
}