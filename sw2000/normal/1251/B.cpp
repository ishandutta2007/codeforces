#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt[2]={0};
        bool flag=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            if(s.length()%2)flag=1;
            for(int j=0;j<s.length();j++)
            {
                cnt[s[j]-'0']++;
            }
        }
        if(flag||cnt[0]%2==0)
        {
            cout<<n<<endl;
        }
        else
        {
            cout<<n-1<<endl;
        }
    }
    return 0;
}