#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)
 
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<n;++i) sum+=s[i]-'0';
    if(!sum) {cout<<"YES"<<endl;return 0;}
    for(int d=1;d<sum;++d)
    {
        if(sum%d) continue;
        int cur=0,ok=1;
        for(int i=0;i<n;++i)
        {
            cur += s[i]-'0';
            if(cur == d) cur = 0;
            if(cur > d) {ok=0;break;}
        }
        if(cur) ok=0;
        if(ok) {cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
}