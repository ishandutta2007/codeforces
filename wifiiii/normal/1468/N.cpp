#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int chk(int c1,int c2,int c3,int a4,int a5)
{
    if(c1<0 || c2<0 || c3<0) return 0;
    int p = min(c1, a4);
    c1 -= p;
    a4 -= p;
    p = min(c2, a5);
    c2 -= p;
    a5 -= p;
    return a4 + a5 <= c3;
}
int main()
{

    // 1 : 1
    // 2 : 2
    // 3 : 3
    // 4 : 1/3
    // 5 : 2/3
    int t;
    cin >> t;
    while(t--)
    {
        int c1,c2,c3;
        cin>>c1>>c2>>c3;
        int a1,a2,a3,a4,a5;
        cin>>a1>>a2>>a3>>a4>>a5;
        c1-=a1,c2-=a2,c3-=a3;
        if(chk(c1,c2,c3,a4,a5)) puts("YES");
        else puts("NO");
    }
}