#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[20];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int len=n;len>=1;len/=2)
    {
        for(int j=1;j+len-1<=n;j+=len)
        {
            int ok = 1;
            for(int k=j;k<j+len-1;++k)
            {
                if(a[k]>a[k+1])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                cout << len << endl;
                return 0;
            }
        }
    }
}