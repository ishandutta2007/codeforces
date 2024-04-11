#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

int n;
int a[200000],ans[200000];
ip b[200000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) scanf("%d",&b[i].first);
	for(int i=0;i<n;i++) b[i].second=i;
	std::sort(b,b+n,[](ip a,ip b){
		if(a.first!=b.first) return a.first<b.first;
		else return a.second>b.second;
	});
	std::sort(a,a+n,[](int a,int b) {return a>b;});
	
	for(int i=0;i<n;i++) ans[b[i].second]=a[i];
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	
	return 0;
}