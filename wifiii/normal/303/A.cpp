#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    forii cout<<i%n<<" ";cout<<endl;
    forii cout<<i%n<<" ";cout<<endl;
    forii cout<<(i+i)%n<<" ";cout<<endl;
}