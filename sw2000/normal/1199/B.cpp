#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;

int main()
{
    double h,l;
    cin>>h>>l;
    double ans=(l*l-h*h)*0.5/h;
    printf("%.13f\n",ans);
    return 0;
}