#include <iostream>
#include <set>
using namespace std;

int N, a[2002], i, j, x, cnt;
set<int> s;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&a[i]); s.insert(a[i]);
	}
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		for(j=1;j<=N;j++){
			if(s.find((x ^ a[j]))!=s.end()) cnt++;
		}
	}
	printf("%s\n",(!(cnt%2))?"Karen":"Koyomi");
	return 0;
}