#include <bits/stdc++.h>
using namespace std;
 
const int pw1=(1<<17), pw2=(1<<18);
 
int main() {
    int n,x;
    cin >> n >> x;
    if(n==1)
        cout << "YES\n"<<x<<"\n";
    else if(n==2&&x==0)
        cout << "NO\n";
    else if(n==2)
        cout << "YES\n0 "<<x<<"\n";
    else
    {
        int i;
        int ans=0;
        cout << "YES\n";
        for(i=1;i<=n-3;i++)
        {
            cout << i << " ";
            ans^=i;
        }
        if(ans==x)
            cout << pw1+pw2 << " " << pw1 << " " << pw2<< "\n";
        else
            cout << pw1 << " " << ((pw1^x)^ans) << " 0 \n";
    }
}