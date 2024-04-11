#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int a[200];
multiset<int> s;

int main()
{
//    freopen("a.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n, B;cin >> n >> B;
    long long int cnti = 0, cntp = 0, ans = 0;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        if(a[i]%2!=0)cnti++;
        else cntp++;
        if(cnti==cntp)s.insert(abs(a[i] - a[i + 1]));
    }

    for(int x : s){
    //  cout << x << endl;
        if(x<=B)B-=x, ans++;
    }

    cout << ans << endl;

    return 0;
}