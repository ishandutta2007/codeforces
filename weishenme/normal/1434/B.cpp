#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,flag[N],x[N],tot,ans[N];
char opt[10];
multiset<int> S;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++){
		scanf("%s",opt);
		if (opt[0]=='-')flag[i]=1,scanf("%d",&x[i]);
	}
	for (int i=2*n;i;i--)
		if (flag[i]){
			if (S.size()&&*S.begin()<x[i]){
				puts("NO");
				return 0;
			}
			S.insert(x[i]);
		}
		else {
			if (!S.size()){
				puts("NO");
				return 0;
			}
			ans[++tot]=*S.begin();
			S.erase(S.begin());
		}
	puts("YES");
	for (int i=tot;i;i--)printf("%d ",ans[i]);
}