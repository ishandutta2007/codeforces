#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;

int main()
{
    int b,g,n;
    cin>>b>>g>>n;
    int cnt=0;
    for(int i=0;i<=b;++i)
        for(int j=0;j<=g;++j)
        {
            if(i+j==n)
            {
                ++cnt;
            }
        }
    cout<<cnt<<endl;
}