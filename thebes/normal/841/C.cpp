#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2e5+5;
int N, i, a[MN], b[MN], ord[MN], ord2[MN], ans[MN];

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
		ord[i] = i;
	}
	for(i=1;i<=N;i++){
		scanf("%d",&b[i]);
		ord2[i] = i;
	}
	sort(ord+1,ord+N+1,[](int i,int j){return a[i]<a[j];});
	sort(ord2+1,ord2+N+1,[](int i,int j){return b[i]>b[j];});
	for(i=1;i<=N;i++){
		ans[ord2[i]] = ord[i];
	}
	for(i=1;i<=N;i++){
		printf("%d ",a[ans[i]]);
	}
	printf("\n");
	return 0;
}