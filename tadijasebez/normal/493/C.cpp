#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int inf=1e9+7;
int max(int a, int b){ return a>b?a:b;}
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
const int N=400050;
int a[N],b[N],ca[N],cb[N];
int main()
{
	int n,m,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.pb(a[i]);
	scanf("%i",&m);
	for(i=1;i<=m;i++) scanf("%i",&b[i]),id.pb(b[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) a[i]=Find(a[i]),ca[a[i]]++;
	for(i=1;i<=m;i++) b[i]=Find(b[i]),cb[b[i]]++;
	int sz=id.size();
	for(i=1;i<=sz;i++) ca[i]+=ca[i-1],cb[i]+=cb[i-1];
	int sol=-inf;
	int f,s;
	for(i=0;i<=sz;i++)
	{
		int ans=2*(ca[i]-cb[i])+3*(n-ca[i]-m+cb[i]);
		if(sol<ans)
		{
			f=2*ca[i]+3*(n-ca[i]);
			s=2*cb[i]+3*(m-cb[i]);
			sol=ans;
		}
	}
	printf("%i:%i\n",f,s);
	return 0;
}