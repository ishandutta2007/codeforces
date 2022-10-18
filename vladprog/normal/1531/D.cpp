#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

#define lock not_lock

const int N=1e5+100;

string s[N];
set<int,greater<int>> good,color;
set<int> lock;

void check(int pos)
{
    if(pos<=0||s[pos].empty())
        return;
    good.erase(pos);
    lock.erase(pos);
    color.erase(pos);
    if(s[pos]=="unlock")
    {
        if(s[pos+1]!="lock"&&s[pos+1]!="unlock")
            good.insert(pos);
    }
    else if(s[pos]=="lock")
        lock.insert(pos);
    else
        color.insert(pos);
}

string solve()
{
    int pos=*good.begin();
    pos=*lock.lower_bound(pos);
    pos=*color.lower_bound(pos);
    return s[pos];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    s[1]="unlock";
    s[2]="blue";
    for(int i=3;i<=n+2;i++)
        cin>>s[i];
    s[n+3]="lock";
    n+=3;
    for(int i=1;i<=n;i++)
        check(i);
    cout<<solve()<<"\n";
    int t;
    cin>>t;
    while(t--)
    {
        int i;
        string msg;
        cin>>i>>msg;
        i+=2;
        s[i]=msg;
        check(i);
        check(i-1);
        cout<<solve()<<"\n";
    }
}