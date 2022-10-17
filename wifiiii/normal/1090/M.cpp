#include<iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int pre = -1;
    int ans = 0, cnt = 0;
    for(int i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a!=pre) cnt++;
        else {ans=max(ans,cnt);cnt=1;}
        pre = a;
    }
    ans = max(ans,cnt);
    cout << ans <<endl;
}