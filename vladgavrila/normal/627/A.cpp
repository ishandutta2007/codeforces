#include <iostream>

using namespace std;

#define maxn 666

long long s, x;
long long d[maxn][2];

int main()
{
    cin>>s>>x;
    d[0][0]=1;
    for(int i=0; i<61; ++i)
    {
        int cs = ((s>>i)&1);
        int cx = ((x>>i)&1);
       // cout<<cs<<cs<<"\n";
        for(int j=0; j<2; ++j)
        {
            for(int a=0; a<2; ++a)
                for(int b=0; b<2; ++b)
                {
                    if((a^b)==cx && (a+b+j)%2==cs)
                    {
                        if(a+b+j<2)
                            d[i+1][0]+=d[i][j];
                        else
                            d[i+1][1]+=d[i][j];
                    }
                }
        }
      //  cout<<d[i+1][0]<<" "<<d[i+1][1]<<"\n";
    }
    if(s==x)
        d[61][0]-=2;
    cout<<d[61][0]<<"\n";

    return 0;
}