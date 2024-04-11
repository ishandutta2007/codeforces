#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1000500;
#define ll long long
vector<int> v;
int BIT[N];
void Set(int i){ for(;i;i-=i&-i) BIT[i]++;}
int Get(int i){ int ret=0;for(;i<N;i+=i&-i) ret+=BIT[i];return ret;}
int a[N],C[N],D[N];
ll sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(i=1;i<=n;i++) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
	for(i=1;i<=n;i++) D[a[i]]++;
	for(i=1;i<=n;i++)
	{
		sol+=Get(D[a[i]]+1);
		C[a[i]]++;
		Set(C[a[i]]);
		D[a[i]]--;
	}
	printf("%lld\n",sol);
	return 0;
}