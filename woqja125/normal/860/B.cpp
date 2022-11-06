#include<stdio.h>
#include<map>
#include<set>
using namespace std;
int d[70001];
map<int, int> cnt[10];
void print(int x, int d){
	int t = x;
	int i = 0;
	for(; t; i++,t/=10);
	if(x==0) i++;
	for(; i<d; i++) printf("0");
	printf("%d\n", x);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%d", d+i);
	for(int i=1; i<=n; i++){
		int m = 1;
		for(int j=1; j<=9; j++){
			m *= 10;
			set<int> x;
			int t = d[i];
			for(int k=1; k<=9-j+1; k++){
				x.insert(t%m);
				t/=10;
			}
			for(auto t:x)cnt[j][t]++;
		}
	}
	for(int i=1; i<=n; i++){
		int m = 1;
		for(int j=1; j<=9; j++){
			m *= 10;
			int t = d[i];
			bool find = false;
			for(int k=1; k<=9-j+1; k++){
				if(cnt[j][t%m] == 1){
					find = true;
					print(t%m, j);
					break;
				}
				t/=10;
			}
			if(find) break;
		}	
	}
	return 0;
}