#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 105;
int T, N, i, j, arr[MN], ok[MN];
vi go;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
		}
		go.clear();
		for(i=1;i<=N;i++){
			scanf("%d",&ok[i]);
			if(!ok[i]){
				go.pb(arr[i]);
			}
		}
		sort(go.begin(),go.end(),[](int i,int j){return i<j;});
		for(i=1;i<=N;i++){
			if(!ok[i]){
				arr[i] = go.back();
				go.pop_back();
			}
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}