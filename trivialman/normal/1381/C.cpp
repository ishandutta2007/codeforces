#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define ar2 array<int,2> 
const int N = 1e5+5;

int a[N], b[N], tmp[N], ptr[N], cnt[N], nsame[N];
int diff, T, n, x, y;

int main() {
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		memset(nsame,0,sizeof nsame);
		scanf("%d%d%d",&n,&x,&y);
		rep(i,1,n) scanf("%d",a+i), cnt[a[i]]++;
		
		priority_queue<ar2, vector<ar2>, std::less<ar2> > heap;
		rep(i,1,n+1) if(cnt[i]){
			heap.push({cnt[i],i});
		}else diff = i;
		
		rep(i,1,x){
			ar2 z = heap.top();
			heap.pop();
			z[0]--;
			nsame[z[1]]++;
			heap.push(z);
		}
		
		int m = 0, ma = 0, tot = 0;
		while(!heap.empty()){
			ar2 z = heap.top();
			heap.pop();
			ma = max(ma, z[0]), tot += z[0];
			ptr[z[1]] = m;
			rep(i,1,z[0]) tmp[++m] = z[1];
		}
		
		if ( (tot-ma) * 2 < y - x) {
			cout<<"NO\n";
			continue;
		}
		
		int nz = y - x;
		rep(i,1,n){
			if (nsame[a[i]]) {
				b[i] = a[i];
				nsame[a[i]]--;
			}else{
				ptr[a[i]]++;
				int ptr1 = ptr[a[i]], xx = tmp[(ptr1+m/2-1)%m + 1];
				if (nz && tmp[ptr1] != xx) 
					b[i] = xx, nz--;
				else
					b[i] = diff;
			}
		}
		
 		printf("YES\n");
		rep(i,1,n) printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}