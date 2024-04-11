#include <bits/stdc++.h>
using namespace std;
int main(){
	int tt;scanf("%i",&tt);
	while(tt--){
		int n,H;scanf("%i%i",&n,&H);
		vector<int> a(n);for(int &i:a)scanf("%i",&i);
		sort(a.begin(),a.end());
		int x=a[n-1],y=a[n-2];
		int full=H/(x+y);
		H-=full*(x+y);
		int bonus=0;
		if(H>0)bonus++,H-=x;
		if(H>0)bonus++,H-=y;
		printf("%i\n",full*2+bonus);
	}
	return 0;
}