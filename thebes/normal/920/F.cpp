#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 3e5+5;
int arr[MN], n, m, i, x, y, w; 
ll bit[MN]; set<int> s;

void upd(int p,int v){for(;p<=n;p+=p&-p)bit[p]+=v;}
ll qu(int p){ll r=0; for(;p>0;p-=p&-p)r+=bit[p]; return r;}
int f(int a){
	int rem=a, cnt=0, ret=1;
	for(int j=2;j<=sqrt(a+0.0);j++){
		while(rem%j==0){
			rem /= j;
			cnt++;
		}
		ret *= (cnt+1);
		cnt = 0;
	}
	return(rem!=1)?ret*2:ret;
}

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
		scanf("%d",&arr[i]),upd(i,arr[i]);
	for(i=1;i<=n;i++)
		if(arr[i]!=1&&arr[i]!=2) s.insert(i);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&w,&x,&y);
		if(w == 2) printf("%lld\n",qu(y)-qu(x-1));
		else{
			auto it = s.lower_bound(x);
			while(it!=s.end()&&*it<=y){
				int tmp = arr[*it];
				arr[*it] = f(arr[*it]);
				upd(*it,arr[*it]-tmp);
				auto it2 = it; it++;
				if(arr[*it2]==1||arr[*it2]==2) s.erase(it2);
			}
		}
	}
	return 0;
}