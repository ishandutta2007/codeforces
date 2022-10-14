#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define N 310
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q,w,h;
ll a[100500], b[100500];
pii ans[100500];
struct info {
    int diff;
    int x;
    int num;
    info(){}
    info(int x, int num){
        this->x = x;
        this->num = num;
    }
};
vector<info> g[2][200500];
bool cmp(info x, info y)
{
    return x.x<y.x;
}
int main() {
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << (a[0]%2&&a[n-1]%2&&n%2?"YES":"NO") << endl;
    return 0;
}