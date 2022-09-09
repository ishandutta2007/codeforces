#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
const int inf=1e9+7;
const ll oo=9e18;
int a[N];
int main()
{
    int n,I;
    scanf("%i %i",&n,&I);
    I*=8;
    for(int i=1;i<=n;i++) scanf("%i",&a[i]);
    int k=I/n;
    int sz=1<<k;
    if(k>20) sz=1e7;
    vector<int> b;
    for(int i=1;i<=n;i++) b.pb(a[i]);
    sort(b.begin(),b.end());
    b.resize(unique(b.begin(),b.end())-b.begin());
    sort(a+1,a+1+n);
    int m=b.size();
    vector<int> c(m+1,0);
    for(int i=0,j=1;i<b.size();i++)
	{
		while(j<=n && b[i]==a[j]) c[i+1]++,j++;
        c[i+1]+=c[i];
	}
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int r=min(m,i+sz);
		int tmp=c[r]-c[i];
		ans=max(ans,tmp);
	}
	printf("%i\n",n-ans);
	return 0;
}