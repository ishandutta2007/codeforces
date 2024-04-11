#include <bits/stdc++.h>
using namespace std;

const int MN=120005;
int arr[MN], n, i, j, x, fnd, ans, t;
map<int,int> mp;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]),mp[arr[i]]++;
	for(i=1;i<=n;i++){
		fnd = 0;
		for(j=0;j<=30;j++){
			if((1<<j)>=arr[i]){
				t = (1<<j)-arr[i];
				if(t==arr[i]&&mp[arr[i]]>1) fnd=1;
				else if(t!=arr[i]&&mp.count(t)) fnd=1;
			}
		}
		if(!fnd) ans++;
	}
	printf("%d\n",ans);
	getchar(); getchar();
}