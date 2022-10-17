#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 mrand(random_device());
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
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    vector<int> ans;
    while(i < j) {
        while(i < s.size() && s[i] != '(') ++i;
        while(j >= 0 && s[j] != ')') --j;
        if(i < j) ans.push_back(i), ans.push_back(j), ++i, --j;
    }
    if(ans.size() == 0) cout << 0 << endl;
    else
    {
        cout << 1 << endl;
        cout << ans.size() << endl;
        sort(all(ans));
        for(int i:ans) cout<<1+i<<" ";
        cout<<endl;
    }
}