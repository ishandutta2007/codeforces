#include <bits/stdc++.h>
using namespace std;
char v[]="codeforces";
long long cnt[15];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n;
    cout<<7+(n-1)*3<<'\n';
    cout<<"0 0\n0 1\n1 0\n1 1\n1 2\n2 1\n2 2\n";
    int cnt=3;
    for(i=1;i<n;++i)
    {
        cout<<cnt<<' '<<cnt<<'\n'<<cnt-1<<' '<<cnt<<'\n'<<cnt<<' '<<cnt-1<<'\n';
        ++cnt;
    }
    return 0;
}