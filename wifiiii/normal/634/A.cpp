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

int a[200005], b[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ii cin >> a[i];
    ii cin >> b[i];
    vector<int> v1,v2;
    ii if(a[i]) v1.push_back(a[i]);
    ii if(b[i]) v2.push_back(b[i]);
    int x=0;
    for(;v2[x]!=v1[0];++x);
    rotate(v2.begin(),v2.begin()+x,v2.end());
    if(v1 == v2) cout << "YES";
    else cout << "NO" << endl;
}