#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int a[188];
int main()
{
    memset(a,-1,sizeof(a));
    for(int i=3;i<=360;++i)
    {
        for(int j=1;j<=i-2;++j)
        {
            if(180*j%i==0 && a[180*j/i]==-1) a[180*j/i]=i;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int ang;
        cin>>ang;
        cout<<a[ang]<<endl;
    }
}