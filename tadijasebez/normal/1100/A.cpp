#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	vector<int> a(n);
	int all=0;
	for(i=0;i<n;i++) scanf("%i",&a[i]),all+=a[i];
	int ans=0;
	for(i=0;i<k;i++)
	{
		int sum=all;
		for(int j=i;j<n;j+=k) sum-=a[j];
		ans=max(ans,abs(sum));
		/*vector<bool> was(n,0);
		for(int j=-n;i+j*k<n;j++) if(i+j*k>=0) was[i+j*k]=1;
		int sum=0;
		for(int j=0;j<n;j++) if(!was[j]) sum+=a[j];
		ans=max(ans,abs(sum));*/
	}
	printf("%i\n",ans);
	return 0;
}