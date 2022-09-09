#include <bits/stdc++.h>
using namespace std;
const int N=1005;
const int S=30;
bitset<N> a[S],f,s[1<<10];
unordered_map<bitset<N>,int> mn;
int main(){
	int n,s,m;
	scanf("%i %i %i",&n,&s,&m);
	for(int i=0;i<s;i++){
		int c,b;scanf("%i",&c);
		while(c--)scanf("%i",&b),a[i][b]=1;
	}
	int k=min(20,s);
	for(int i=0;i<1<<k;i++){
		f.reset();
		for(int j=0;j<k;j++)
			if(i>>j&1)
				f^=a[j];
		int pc=__builtin_popcount(i);
		if(!mn.count(f)||mn[f]>pc)mn[f]=pc;
	}
	for(int i=0;i<1<<(s-k);i++){
		for(int j=0;j<(s-k);j++)
			if(i>>j&1)
				::s[i]^=a[k+j];
	}
	while(m--){
		bitset<N> now,tmp;
		int c,b;scanf("%i",&c);
		while(c--)scanf("%i",&b),now[b]=1;
		int ans=N;
		for(int i=0;i<1<<(s-k);i++){
			int pc=__builtin_popcount(i);
			tmp=now^::s[i];
			if(mn.count(tmp))ans=min(ans,mn[tmp]+pc);
		}
		printf("%i\n",ans==N?-1:ans);
	}
	return 0;
}