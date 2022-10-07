#include <iostream>
using namespace std;
int n,m,k,x,y,i,l[100100],r[100100],d[100100],b[100100];
long long a[100100],c[100100],cnt,cur;
main()
{
  cin>>n>>m>>k;
  for (i=1; i<=n; i++) cin>>a[i];
  for (i=1; i<=m; i++) cin>>l[i]>>r[i]>>d[i];
  for (i=1; i<=k; i++)
 {
    cin>>x>>y;
	b[x]++;
	b[y+1]--;
  }
  for (i=1; i<=m; i++) 
{
    cnt+=b[i];
	c[l[i]]+=cnt*d[i];
	c[r[i]+1]-=cnt*d[i];
  }
  for (i=1; i<=n; i++) 
{
    cur+=c[i];
	a[i]+=cur;
  }
  for (i=1; i<=n; i++) cout<<a[i]<<" "; i==n?'\n':' ';
}