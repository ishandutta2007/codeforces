#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
struct A{int fi,se,rev;}a[N];
int solve()
{
    cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i].fi>>a[i].se;
        if(a[i].fi>a[i].se)
        {
            swap(a[i].fi,a[i].se);
            a[i].rev=1;
        }
        if(a[i].fi>n||a[i].se<=n)return -1;
    }
    sort(a+1,a+1+n,[](A a,A b){return a.fi<b.fi;});
    int ret=0,cnt=0,m1=1e9,m2=1e9;
    for(int l=0,r=1;r<=n;r++)
    {
        if(a[r].se<m1)m1=a[r].se;
        else if(a[r].se<m2)
        {
            m2=a[r].se;
            a[r].rev^=1;
        }
        else return -1;
        cnt+=a[r].rev;
        if(m1+r==2*n+1)
        {
            ret+=min(cnt,r-l-cnt);
            cnt=0,l=r;
        }
    }
    return ret;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cout<<solve();
	return 0;
}