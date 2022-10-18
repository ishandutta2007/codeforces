#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>k;
    char s[6]="aeiou";
    for(int n=5;n*n<=k;n++)
        if(k%n==0)
        {
            int m=k/n;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    cout<<s[(i+j)%5];
            exit(0);
        }
    cout<<-1;
}