#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100010;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string a;
        cin>>a;
        map<int,int>m;
        for(int i=0,len=a.length();i<len;i++)
        {
            m[a[i]-'a']++;
        }
        int part=0,sum=0;
        for(int i=0;i<26;i++)
        {
            if(m[i]!=0&&m[i+1]==0)part++;
            if(m[i])sum++;
        }
        if(part==1&&(sum==3||sum==2))printf("No answer\n");
        else
        {
            string ans1,ans2;
            for(int i=0;i<26;i+=2)ans1.insert(ans1.end(),m[i],i+'a');
            for(int i=1;i<26;i+=2)ans2.insert(ans2.end(),m[i],i+'a');
            if(abs(*(ans1.end()-1)-*(ans2.begin()))==1)
            {
                cout<<ans2<<ans1<<endl;
            }
            else cout<<ans1<<ans2<<endl;
        }
    }
    return 0;
}