#include<bits/stdc++.h>
using namespace std;

const int N = 4000005;

map<int,int>M , C;
map<int,int>::iterator it;

int now[N] , id[N] , n , m , ans[N] , L[N] , R[N] , cnt = 0 , tot , k , al[N] , ar[N] , all;

int main(void) {
	scanf("%d",&n); cin>>k;
	for(int i = 1;i <= n;i ++) scanf("%d%d",&L[i] , &R[i]) , M[L[i]] ++ , M[R[i]] ++;
	for(it = M.begin(); it != M.end(); it ++) {
		 int xx = it -> first;
		 cnt += 2;
		 C[xx] = cnt; id[cnt] = xx;
	}
	for(int i = 1;i <= n;i ++) L[i] = C[L[i]] , R[i] = C[R[i]] , now[L[i]] ++ , now[R[i] + 1] --;
	for(int i = 1;i <= cnt;i ++) now[i] += now[i - 1];
	for(int i = 1;i <= cnt;i ++) {
		if(now[i] >= k) ans[++ tot] = i;
	}
		
	bool yes = 0; int l = 0 , r = 0 , last;
	
	for(int i = 1;i <= tot;i ++) {
		 if(!yes) {
		 	all ++; l = id[ans[i]] , r = l , last = ans[i];
		 	yes = 1;
		 } 
		 else {
		 	if(ans[i] == last + 1) {
		 		r = id[ans[i]] ,last = ans[i]; continue;
			 }
			 else {
			 	yes = 0; L[all] = l , R[all] = r;
			 	all ++; l = id[ans[i]] , r = l , last = ans[i]; yes = 1; 
			 }
		 }
	}
	L[all]= l , R[all] = r;
	cout<<all<<endl;
	for(int i = 1;i <= all;i ++) printf("%d %d\n",L[i] , R[i]);
}