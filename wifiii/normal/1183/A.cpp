#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int sum(int x)
{
    int ret=0;
    while(x) ret+=x%10,x/=10;
    return ret;
}
int main()
{
    int n;
    cin>>n;
    while(1)
    {
        if(sum(n)%4==0)
        {
            cout<<n<<endl;
            break;
        }
        n++;
    }
}