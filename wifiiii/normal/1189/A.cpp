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
    int cnt0=0,cnt1=0;
    for(int i=0;i<s.size();++i) if(s[i]=='1') cnt1++;else cnt0++;
    if(cnt1!=cnt0) cout<<"1\n"<<s<<endl;
    else cout<<"2\n"<<s.substr(0,1)<<" "<<s.substr(1,s.size()-1)<<endl;
}