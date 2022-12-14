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
int x1,x2,yy1,y2;
int solve()
{
    cin>>x1>>yy1>>x2>>y2;
    int ret=abs(x1-x2)+abs(yy1-y2);
    if(x1==x2||yy1==y2)return ret;
    else return ret+2;
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