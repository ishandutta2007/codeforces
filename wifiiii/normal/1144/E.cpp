#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'


int a[1000005];
int main()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<n;++i) a[i] += s1[i]-'a';
    for(int i=0;i<n;++i) a[i] += s2[i]-'a';
    for(int i=n-1;i>0;--i) a[i-1]+=a[i]/26,a[i]%=26; 
    for(int i=0;i<n;++i)
    {
        if(a[i] & 1) a[i+1] += 26;
        a[i] /= 2;
        cout << (char)(a[i] + 'a');
    }
}