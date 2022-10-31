#include <bits/stdc++.h>
using namespace std;

int n,m,b[200001],c[200001],a[200001],ac[200001];
vector<int> arr;

int main() {
	int val;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i),arr.push_back(a[i]);
	
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",b+i);
	for(int i=0;i<m;i++) scanf("%d",c+i);
	
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	
	for(int i=0;i<n;i++) ac[lower_bound(arr.begin(),arr.end(),a[i])-arr.begin()]++;

	int id=-1,mb=-1,mc=-1;
	for(int i=0;i<m;i++) {
		int bb=0,cc=0;
		int ib=lower_bound(arr.begin(),arr.end(),b[i])-arr.begin();
		if(ib!=arr.size() && arr[ib]==b[i]) bb=ac[ib];
		
		int ic=lower_bound(arr.begin(),arr.end(),c[i])-arr.begin();
		if(ic!=arr.size() && arr[ic]==c[i]) cc=ac[ic];
		
		if(mb<bb || (mb==bb && mc<cc)) {
			id=i;
			mb=bb;
			mc=cc;
		}
	}

	printf("%d\n",id+1);

	return 0;
}