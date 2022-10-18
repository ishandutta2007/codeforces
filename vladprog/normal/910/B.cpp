#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int m=6;
    for(int i=0;i<6;i++)
        for(int j=i+1;j<6;j++)
        {
            int t=0,l=0;
            for(int k=0;k<6;k++)
            {
                int p=(k==i||k==j)?b:a;
                if(p>l)
                    t++,l=n;
                l-=p;
            }
            m=min(m,t);
        }
    cout<<m;
}