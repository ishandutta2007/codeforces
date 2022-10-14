#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,a[N];
int main(){
	int t;scanf("%i",&t);
	while(t--){
		scanf("%i",&n);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]);
		reverse(a+1,a+n+1);
		int ans=0;
		while(*max_element(a+1,a+n+1)!=*min_element(a+1,a+n+1)){
			ans++;
			int ptr=1;
			while(ptr+1<=n&&a[ptr+1]==a[ptr])ptr++;
			for(int i=1;i<=ptr;i++)if(ptr+i<=n)a[ptr+i]=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}