#include <bits/stdc++.h>
using namespace std;
const int N=100050;
bitset<4096> S[N];
int X[12][N];
int main()
{
	int n,k,q,i,j,t,x,y;
	scanf("%i%i%i",&n,&k,&q);
	for(i=0;i<k;i++){
		for(j=0;j<4096;j++)if(j&(1<<i))S[i+1].set(j);
		for(j=0;j<n;j++)scanf("%i",&X[i][j]);
	}
	int c=k;
	vector<pair<int,int> > m;
	while(q--){
		scanf("%i%i%i",&t,&x,&y);
		if(t==1)S[++c]=S[x]&S[y];
		if(t==2)S[++c]=S[x]|S[y];
		if(t==3){
			m.clear();
			for(i=0;i<k;i++)m.push_back({X[i][y-1],i});
			sort(m.begin(),m.end());
			int b=0;
			for(i=0;i<k;i++){
				b|=1<<m[i].second;
				if(S[x][b]){printf("%i\n",m[i].first);break;}
			}
		}
	}
	return 0;
}