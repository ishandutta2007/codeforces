#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int calc(string s)
{
    int cur[2]={0,0},mx[2]={5,5};
    for(int i=0;i<10;i++)
    {
        if(cur[0]>mx[1]||cur[1]>mx[0])
            return i;
        if(s[i]=='1')
            cur[i%2]++;
        else
            mx[i%2]--;
    }
    return 10;
}

int solve()
{
    string s;
    cin>>s;
    string a=s,b=s;
    for(int i=0;i<10;i++)
        if(s[i]=='?')
            if(i%2)
                a[i]='0',b[i]='1';
            else
                a[i]='1',b[i]='0';
    return min(calc(a),calc(b));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<"\n";
}