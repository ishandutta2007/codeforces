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
//#define endl '\n'

int main()
{
    int f = 1;
    cout << "a" << endl;
    int x;
    cin>>x;
    string s(x+1,'a');
    if(sz(s) > 300) s = string(300, 'a'), f = 0;
    cout << s << endl;
    cin>>x;
    if(x==s.size()) return cout<<string((int)s.size()-f,'b')<<endl,0;
    if(!x) return 0;
    int last = x;
    for(int i=0;i<s.size();++i)
    {
        s[i] = 'b';
        cout << s << endl;
        cin >> x;
        if(x > last) s[i] = 'a';
        else last = x;
        if(!x) return 0;
    }
    s.pop_back();
    cout << s << endl;
}