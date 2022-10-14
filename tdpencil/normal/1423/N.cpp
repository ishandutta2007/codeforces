#include<bits/stdc++.h>
#define F(i,j,k) for(int i=(j);i<=(k);i++)
using namespace std;
const int N=1e6+100;
int x[N],y[N],w[N],s[N],v[N];
vector <pair<int,int> > e[N];
vector <int> res;
int main(){
 	int n,m;scanf("%d%d",&n,&m);
 	F(i,1,m){
 		scanf("%d%d",x+i,y+i);w[i]=1;s[x[i]]++;s[y[i]]++;
 		e[max(x[i],y[i])].push_back(make_pair(min(x[i],y[i]),i));
 	}
 	F(i,1,n){
 		set <int> in;
 		for(auto it:e[i]){if(!v[it.first]){v[it.first]=1;w[it.second]=0;s[i]--;}in.insert(s[it.first]);}
 		for(auto it:e[i]){if(in.find(s[i])==in.end())break;s[i]++;v[it.first]=0;w[it.second]++;}
 	}
 	F(i,1,n)if(v[i])res.push_back(i);
 	printf("%d\n",int(res.size()));
 	for(auto it:res)printf("%d ",it);puts("");
 	F(i,1,m)printf("%d %d %d\n",x[i],y[i],w[i]);
    return 0;
}