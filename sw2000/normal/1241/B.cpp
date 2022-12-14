#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        string s,t;
        bool flag=0;
        cin>>s>>t;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.length();j++)
            {
                if(s[i]==t[j])
                {
                    cout<<"YES"<<endl;
                    flag=1;
                }
                if(flag)break;
            }
            if(flag)break;
        }
        if(flag)continue;
        cout<<"NO"<<endl;
    }
	return 0;
}