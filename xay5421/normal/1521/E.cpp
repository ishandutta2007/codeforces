// author: xay5421
// created: Sat May  8 21:04:37 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int T,m,K,n,a[N],id[N],mp[1005][1005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&K);
		rep(i,1,K)scanf("%d",&a[i]),id[i]=i;
		sort(id+1,id+1+K,[&](int x,int y){return a[x]>a[y];});
		n=1;
		while(((n&1)&&(a[id[1]]>n*n-(n/2)*(n/2)-(n+1)*(n-1)/4||m>n*n-(n/2)*(n/2)))||((~n&1)&&(a[id[1]]>n*n-n*n/4-n*n/4||m>n*n-n*n/4)))++n;
		vector<pair<int,int> >black,blue,yellow;
		rep(i,1,n)rep(j,1,n){
			if((i&1)&&(~j&1))blue.emplace_back(i,j);
			if((~i&1)&&(j&1))yellow.emplace_back(i,j);
			if((i&1)&&(j&1))black.emplace_back(i,j);
		}
		rep(i,1,n)rep(j,1,n)mp[i][j]=0;
		rep(i,1,K){
			while(a[id[i]]--){
				pair<int,int>cur;
				if(SZ(blue)){
					cur=blue.back();
					blue.pop_back();
				}else if(SZ(black)){
					cur=black.back();
					black.pop_back();
				}else{
					assert(SZ(yellow));
					cur=yellow.back();
					yellow.pop_back();
				}
				mp[cur.first][cur.second]=id[i];
			}
		}
		printf("%d\n",n);
		rep(i,1,n)rep(j,1,n)printf("%d%c",mp[i][j],j==n?'\n':' ');
	}
	return 0;
}