#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
int inf=0x3f3f3f3f;
using namespace std;
int main()
{
    int q;
    cin>>q;
    {
        while(q--)
        {
            long long n,a,b;
            cin>>n>>a>>b;
            if(2*a<=b)
            {
                cout<<a*n<<endl;
                continue;
            }
                cout<<(n/2)*b+(n%2)*a<<endl;
        }
    }
    return 0;
}