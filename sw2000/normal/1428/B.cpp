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
    string s;
    cin>>n>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='<')break;
        else if(i==s.size()-1)return n;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='>')break;
        else if(i==n-1)return n;
    }

    s+=s[0];
//    cout<<s<<endl;
    int ret=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='-'||s[i+1]=='-')ret++;
    }
    return ret;
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