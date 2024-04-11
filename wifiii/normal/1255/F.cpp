#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
//#define endl '\n'

ll s[1005];
int main()
{
    int n;
    cin>>n;
    vector<int> up,down;
    ll res = 0;
    for(int i=3;i<=n;++i)
    {
        cout << 2 << " " << 1 << " " << 2 << " " << i << endl;
        cin >> res;
        if(res > 0) up.push_back(i);
        else down.push_back(i);
    }
    vector<int> upans;
    if(up.size())
    {
        for(int p : up)
        {
            cout << 1 << " " << 1 << " " << 2 << " " << p << endl;
            cin >> res;
            s[p] = res;
        }
        int mi = up[0];
        for(int p : up)
        {
            if(s[p] > s[mi]) mi = p;
        }
        vector<int> left, right;
        for(int p : up)
        {
            if(mi == p) continue;
            cout << 2 << " " << 1 << " " << mi << " " << p << endl;
            cin >> res;
            if(res > 0) left.push_back(p);
            else right.push_back(p);
        }
        sort(all(right), [&](int i,int j){return s[i] < s[j];});
        sort(all(left), [&](int i,int j){return s[i] > s[j];});
        for(int i : right) upans.push_back(i);
        upans.push_back(mi);
        for(int i : left) upans.push_back(i);
    }
    vector<int> downans;
    if(down.size())
    {
        for(int p : down)
        {
            cout << 1 << " " << 1 << " " << 2 << " " << p << endl;
            cin >> res;
            s[p] = res;
        }
        int mi = down[0];
        for(int p : down)
        {
            if(s[p] > s[mi]) mi = p;
        }
        vector<int> left, right;
        for(int p : down)
        {
            if(mi == p) continue;
            cout << 2 << " " << 1 << " " << mi << " " << p << endl;
            cin >> res;
            if(res > 0) right.push_back(p);
            else left.push_back(p);
        }
        sort(all(left), [&](int i,int j){return s[i] < s[j];});
        sort(all(right), [&](int i,int j){return s[i] > s[j];});
        for(int i : left) downans.push_back(i);
        downans.push_back(mi);
        for(int i : right) downans.push_back(i);
    }
    cout << 0 << " ";
    cout << 1 << " ";
    for(int i : downans) cout << i << " ";
    cout << 2 << " ";
    for(int i : upans) cout << i << " ";
    cout << endl;
}