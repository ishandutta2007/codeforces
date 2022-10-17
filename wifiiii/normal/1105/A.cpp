#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;

int a[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans1=1,ans2=1e9;
    for(int i=1;i<=100;++i)
    {
        int cost  = 0;
        for(int j=1;j<=n;++j)
        {
            cost += max(0,abs(i-a[j])-1);
        }
        if(cost < ans2)
        {
            ans1 = i, ans2 = cost;
        }
    }
    cout << ans1 << " " << ans2 << endl;
}