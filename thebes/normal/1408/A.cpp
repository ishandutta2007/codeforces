#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 105;
int T, N, i, a[MN], b[MN], c[MN], pre;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++) scanf("%d",&a[i]);
		for(i=1;i<=N;i++) scanf("%d",&b[i]);
		for(i=1;i<=N;i++) scanf("%d",&c[i]);
		pre = -1; int fs = 0;
		for(i=1;i<N;i++){
			if(a[i]!=pre){
				printf("%d ",a[i]);
				pre = a[i];
			}
			else if(b[i]!=pre){
				printf("%d ",b[i]);
				pre = b[i];
			}
			else{
				printf("%d ",c[i]);
				pre = c[i];
			}
			if(i==1) fs = pre;
		}
		if(a[N]!=pre&&a[N]!=fs){
			printf("%d\n",a[N]);
		}
		else if(b[N]!=pre&&b[N]!=fs){
			printf("%d\n",b[N]);
		}
		else printf("%d\n",c[N]);
	}
	return 0;
}