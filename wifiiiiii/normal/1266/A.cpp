#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int sum=0;
        int f0=0,f2=0;
        for(int i=0;i<s.size();++i) {
            sum+=s[i]-'0';
            if(s[i]=='0') f0++;
            if(s[i]!='0' && (s[i]-'0')%2==0) f2++;
        }
        if(f0>1) f2=1;
        if(f0&&f2&&sum%3==0) cout<<"red"<<endl;
        else cout<<"cyan"<<endl;
    }
}