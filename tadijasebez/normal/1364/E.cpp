#include <bits/stdc++.h>
using namespace std;
int ask(int i,int j){
	printf("? %i %i\n",i,j);
	fflush(stdout);
	int b;scanf("%i",&b);
	return b;
}
int main(){
	int n;scanf("%i",&n);
	int a=1,b=2,ab=ask(a,b);
	for(int c=3;c<=n;c++){
		int bc=ask(b,c);
		if(ab>bc){
			a=c;
			ab=bc;
		}else if(ab==bc){
			b=c;
			ab=ask(a,b);
		}
	}
	mt19937 rng(time(0));
	map<int,bool> was;was[a]=was[b]=1;
	int nula;
	while(1){
		int c=rng()%n+1;
		if(was[c])continue;
		int bc=ask(b,c);
		int ac=ask(a,c);
		if(bc<ac){
			nula=b;
			break;
		}else if(ac<bc){
			nula=a;
			break;
		}
	}
	vector<int> ans;
	for(int i=1;i<=n;i++)ans.push_back(i==nula?0:ask(i,nula));
	printf("! ");
	for(int i:ans)printf("%i ",i);
	printf("\n");
	fflush(stdout);
	return 0;
}