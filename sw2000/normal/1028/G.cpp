#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[10],ans[10010];

ll dfs(ll l,int d)
{
	if(l>=10000)return f[d];
	if(d==0)return 0;
	ll r=l;
	for(int i=1;i<=min(l,10000ll);i++)
		r+=dfs(r,d-1)+1;
	r+=dfs(r,d-1);
	return r-l;
}
int main()
{
	f[1]=10000;
	for(int i=2;i<=4;i++)
		f[i]=f[i-1]*10001+10000;
	ll l=1;
	for(int i=5;i;i--)
    {
        ll r=l;
        cout<<min(l,10000ll);
        for(int j=1;j<=min(l,10000ll);j++)
        {
            r+=dfs(r,i-1);
            cout<<' '<<r;
            ans[j]=++r;
        }
        cout<<endl;
		int op;cin>>op;
		if(op==-1)return 0;
		if(op)l=ans[op];
	}
	return 0;
}