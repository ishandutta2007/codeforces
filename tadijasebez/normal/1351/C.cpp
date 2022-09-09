#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
pii operator+(pii a,char b){
	if(b=='N')a.first--;
	if(b=='S')a.first++;
	if(b=='E')a.second--;
	if(b=='W')a.second++;
	return a;
}
const int N=100050;
char s[N];
int main(){
	int t;scanf("%i",&t);
	while(t--){
		set<set<pii>> was;
		scanf("%s",s+1);int n=strlen(s+1);
		int ans=0;pii pos={0,0};
		for(int i=1;i<=n;pos=pos+s[i],i++)ans+=was.count({pos,pos+s[i]})?1:5,was.insert({pos,pos+s[i]});
		printf("%i\n",ans);
	}
	return 0;
}