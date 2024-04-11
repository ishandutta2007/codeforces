#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c,d;};
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

int d[100], cnt;
void add(int a)
{
    for(int i = 19; ~i; i--)
    {
        if(a & (1 << i))
        {
            if(d[i])
                a ^= d[i];
            else
            {
                d[i] = a;
                cnt++;
                break;
            }
        }
    }
}
bool can(int a)
{
    for(int i = 19; ~i; i--)
    {
        if(a & (1 << i))
        {
            if(!d[i])
                return 0;

            a ^= d[i];
        }
    }
    return 1;
}
int n, m, two[N], arr[N];
tri brr[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    two[0] = 1;
    for(int i = 1; i < N; i++)
        two[i] = two[i - 1] * 2 % mod;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i < m; i++)
    {
        cin >> brr[i].a >> brr[i].b;
        brr[i].c = i;
    }
    sort(brr, brr + m, [](tri a, tri b) {return a.a < b.a;});
    for(int i=0,id=0;i<m;i++)
    {
        while(id!=brr[i].a)
        {
            add(arr[++id]);
        }
        if(!can(brr[i].b))brr[i].d=0;
        else
        {
            brr[i].d=two[brr[i].a-cnt];
        }
    }
    sort(brr, brr + m, [](tri a, tri b) {return a.c < b.c;});
    for(int i=0;i<m;i++)
        cout<<brr[i].d<<endl;

    return 0;
}