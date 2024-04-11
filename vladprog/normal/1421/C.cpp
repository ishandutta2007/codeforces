#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=210;

string s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    cout<<3<<"\n";
    cout<<"R "<<n-1<<"\n";
    cout<<"L "<<n<<"\n";
    cout<<"L "<<2<<"\n";
}