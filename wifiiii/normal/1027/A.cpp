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
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

bool almostsame(char a,char b)
{
    if(abs(a-b)==0 || abs(a-b)==2) return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;string s;
        cin>>n>>s;
        int i=0,j=s.size()-1;
        int ok = 1;
        while(i<j) {if(almostsame(s[i],s[j])==0){ok=0;break;}++i;--j;}
        cout << (ok?"YES":"NO") << endl;
    }
}