#include <bits/stdc++.h>
using namespace std;
const int maxn=2000+50;
int n;
long long w[maxn],v[maxn];
long long f[maxn*2];
int main()
{
    long long mn=1e15+1e2,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        w[i]++;
        mx=max(mx,w[i]);
    }
    mx+=n;
    for(int i=1;i<=mx;i++)	f[i]=1e15+1e2;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=mx;j>=w[i];j--)
    	{
    		f[j]=min(f[j],f[j-w[i]]+v[i]);
    		if(j>=n)	mn=min(mn,f[j]);
    	}
    }
    cout<<mn<<endl;;
    return 0;
}