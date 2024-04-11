#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		scanf("%s",s+1);
		map<pair<int,int>,int> fir;
		int x=0,y=0,ans=n+1,l=-1,r=-1;
		fir[{0,0}]=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='L')x--;
			if(s[i]=='R')x++;
			if(s[i]=='U')y++;
			if(s[i]=='D')y--;
			if(fir.count({x,y})){
				ans=min(ans,i-fir[{x,y}]);
				if(ans==i-fir[{x,y}])l=fir[{x,y}]+1,r=i;
			}
			fir[{x,y}]=i;
		}
		if(ans<=n)printf("%i %i\n",l,r);
		else printf("-1\n");
	}
	return 0;
}