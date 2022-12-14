#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double ld;
vector<pair<ld,int> >v;
int main(){
	ld mn=1000000;
	int n,a,b;
	scanf("%d",&n);
	for(int i=0,x,y; i<n; ++i){
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(atan2(y,x),i+1));
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; ++i){
		ld tmp=v[(i+1)%n].first-v[i].first;
		if(tmp<0)
			tmp+=acos(-1)*2;
		if(tmp<mn)
			mn=tmp,a=v[i].second,b=v[(i+1)%n].second;
	}
	printf("%d %d\n",a,b);
	return 0;
}