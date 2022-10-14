#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int S=100;
int n,q,p[N],jmp[N],prv[N];
void upd(int x){
	int pos=x;
	for(int i=0;i<S;i++)pos=p[pos];
	jmp[x]=pos;
}
int main(){
	scanf("%i%i",&n,&q);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]),prv[p[i]]=i;
	for(int i=1;i<=n;i++)upd(i);
	while(q--){
		int t;
		scanf("%i",&t);
		if(t==1){
			int x,y;
			scanf("%d%d",&x,&y);
			swap(p[x],p[y]);
			swap(prv[p[x]],prv[p[y]]);
			vector<int> todo;
			todo.pb(x);
			for(int i=0;i<S;i++)x=prv[x],todo.pb(x);
			todo.pb(y);
			for(int i=0;i<S;i++)y=prv[y],todo.pb(y);
			for(int i:todo)upd(i);
		}else{
			int i,k;
			scanf("%i%i",&i,&k);
			while(k){
				if(k>=S)i=jmp[i],k-=S;
				else i=p[i],k--;
			}
			printf("%i\n",i);
		}
	}
	return 0;
}