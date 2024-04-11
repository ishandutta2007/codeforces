#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

string s = "aeiou";
int main()
{
    int k;
    cin>>k;
    for(int i=5;i*i<=k;++i)
    {
        if(k%i==0)
        {
            if(k/i>=5)
            {
                int n = 0;
                for(int j=1;j<=i;++j)
                {
                    int n2 = n;
                    for(int p=1;p<=k/i;++p)
                    {
                        cout<<s[n2%5];
                        ++n2;
                    }
                    n++;
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}