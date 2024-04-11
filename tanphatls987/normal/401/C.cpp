#include <iostream>

using namespace std;
int main()
{
    int n,m,i;
    cin>>n>>m;
    if ((n<=m+1)&&(m<=2*n+2))
        {
            if (n==m+1) {for (i=1;i<=m;i++) cout<<"01";cout<<"0";}
            else
                {int k=m-n;if (m>2*n) k=n;
                    for (i=1;i<=k;i++) cout<<"110";
                    n-=k;m-=2*k;
                while (m+n)
                {if (m) {cout<<"1";m--;}
                if (n) {cout<<"0";n--;}}
                }
        }
    else cout<<-1;
    return(0);
}