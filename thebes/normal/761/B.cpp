#include <bits/stdc++.h>
using namespace std;

int n, l, i, x, a[55], b[55], fnd;
vector<int> tmp;
int main(){
	for(scanf("%d%d",&n,&l),i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=l;i++){
		bool wow = 0;tmp.clear();
		for(int j=1;j<=n;j++)
			tmp.push_back((a[j]+i)%l);
		sort(tmp.begin(),tmp.end());
		for(int j=0;j<n;j++)
			if(tmp[j]!=b[j+1]) wow=1;
		if(!wow){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}