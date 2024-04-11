#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;scanf("%i",&n);
	bool have[3]={0,0,0};
	have[n-1]=true;
	for(int i=0;i<3;i++){
		int x,y;scanf("%i%i",&x,&y);
		--x,--y;
		swap(have[x],have[y]);
	}
	for(int i=0;i<3;i++)if(have[i])printf("%i",i+1);
	return 0;
}