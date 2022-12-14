#include <bits/stdc++.h>
#define first fi
#define second se
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

int n,arr[N];
int solve()
{
    string s;
    cin>>s;
    n=s.size();
    int a=0,b=0;
    for(auto i:s)
    {
        if(i=='A')
        {
            a++;
        }
        else
        {
            if(a)a--;
            else b++;
        }
    }
    return a+b%2;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;cin>>_;
    while(_--)
        cout<<(solve())<<endl;
    return 0;
}