#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

int a[500];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int t;cin>>t;
        a[t]++;
    }
    for(int i=1;i<=50;++i)
    {
        if(a[i])
        {
            if(a[i]>n/2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
            break;
        }
    }
}