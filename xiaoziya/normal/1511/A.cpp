#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans1,ans2;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans1=ans2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1)
				ans1++;
			if(a[i]==2)
				ans2--;
			if(a[i]==3){
				if(ans1>=0)
					ans1++;
				else ans2--;
			}
		}
		printf("%d\n",ans1);
	}
	return 0;
}