#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

#define def(OP) \
int OP(int i,int j) \
{ \
    cout<<#OP<<" "<<i<<" "<<j<<endl; \
    int resp; \
    cin>>resp; \
    if(resp==-1) \
        cout<<0/0,exit(1); \
    return resp; \
}
def(AND)
def(OR)
def(XOR)

const int N=(1<<16)+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        a[i]=XOR(1,i);
    map<int,int> pos;
    for(int i=1;i<=n;i++)
        if(pos.count(a[i]))
        {
            int j=pos[a[i]];
            int val=AND(i,j);
            int x=a[i]^val;
            cout<<"! ";
            for(int i=1;i<=n;i++)
                cout<<(a[i]^x)<<" ";
            exit(0);
        }
        else
            pos[a[i]]=i;
    int pos1=pos[1],
        pos2=pos[2];
    int val1=AND(1,pos1),
        val2=AND(1,pos2);
    int x=val1|val2;
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<(a[i]^x)<<" ";
}