#include <iostream>
#include <vector>
using namespace std;

int n, k, arr[100005], f[100005], s[100005], i, x=-(1<<30), ans=-(1<<30);
vector<int> pos;
int getMin(int l, int r){
	int ret = 1<<30;
	while(l <= r) ret=min(ret,arr[l++]);
	return ret;
}

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(arr[i] > x){pos.clear(); pos.push_back(i); x = arr[i];}
		else if(arr[i] == x) pos.push_back(i);
	}
	if(k == 1) printf("%d\n",getMin(1,n));
	else if(k == 2){
		if(pos[0] == 1 || pos.back() == n) printf("%d\n",x);
		else{
			for(x=1<<30,i=1;i<=n;i++){
				x = min(x, arr[i]);
				f[i] = x;
			}
			for(x=1<<30,i=n;i>=1;i--){
				x = min(x, arr[i]);
				s[i] = x;
			}
			for(i=1;i<=n-1;i++)
				ans = max(ans,max(f[i],s[i+1]));
			printf("%d\n",ans);
		}
	}
	else if(k >= 3) printf("%d\n",x);
	return 0;
}