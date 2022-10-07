#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
#define N 1000005
using namespace std;
long long n,k,a,usj=1,usg;
int main()
{
    cin>>n>>k;
    while (n--){
        scanf("%lld",&a);
        usj=usj*a/__gcd(a,usj);
        usj=__gcd(usj,k);
        if (usj==k){cout<<"Yes"<<endl;return 0;}
    }
    cout<<"No"<<endl;
    return 0;
}