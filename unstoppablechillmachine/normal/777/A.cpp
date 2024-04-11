#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define itn int
#define fro for
#define f first
#define sec second

int n,m,sum,kol,a[5],k;
vector<int> Vec,Vec1;
set<int> st;
string s,s1,s2;
bool t,t1;


int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    n%=60;
    a[k]=1;
    if (!n) n+=4;
    for (int i=n;i>0;i--)
    {
        if (i%2==1) swap(a[0],a[1]);
        else swap(a[1],a[2]);
    }

    for (int i=0;i<3;i++) if (a[i]) cout<<i;

    return 0;
}