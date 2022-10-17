#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string a(n,'0'),b(n,'0');
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == '2') a[i] = b[i] = '1';
            else if(s[i] == '0') a[i] = b[i] = '0';
            else
            {
                a[i] = '1'; b[i] = '0';
                for(int j=i+1;j<s.size();++j) b[j] = s[j];
                break;
            }
        }
        cout << a << endl << b << endl;
    }
}