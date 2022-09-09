#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int cnt[1005],ans;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,a;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a),v.push_back(a),cnt[a]++;
	for(i=0;i<1001;i++) ans=max(ans,cnt[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	printf("%i %i\n",ans,v.size());
}