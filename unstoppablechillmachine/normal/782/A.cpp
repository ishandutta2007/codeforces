#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second

const ld eps=0.00000001;

vector<int> Vec;
int sum,max1,n,a;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    Vec.resize(n+1);
    for (int i=0;i<2*n;i++)
    {
        cin>>a;
        if (!Vec[a])
        {
            sum++;
            Vec[a]++;
        }
        else sum--;
        max1=max(max1,sum);
    }

    cout<<max1;



    return 0;
}