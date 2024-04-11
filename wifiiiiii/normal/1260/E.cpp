#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1<<19];
int main()
{
    priority_queue<int,vector<int>,greater<int>> q;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int rk = 0;
    int n;
    cin>>n;
    ii cin>>a[i];
    ii if(a[i] == -1) rk = i;
    for(int i=1;i<rk;++i) a[i] = 0;
    if(rk == n) return cout << 0 << endl,0;
    ll tot = 0;
    q.push(a[n]);
    int p = __builtin_ctz(n);
    int cur = n - 1;
    while(p >= 1)
    {
        p--;
        tot += q.top(); q.pop();
        for(int i=0;i<1<<p;++i)
        {
            if(a[cur] == -1) --cur;
            q.push(a[cur]);
            cur--;
        }
    }
    cout << tot << endl;
}