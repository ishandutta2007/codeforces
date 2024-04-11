#include<cstdio>
int rd(){std::fflush(stdout);int n;scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%*s");return n;}
int main(){
	while(1){printf("next 0\n");rd();printf("next 0 1\n");if(rd()==2)break;}
	while(1){printf("next 0 1 2 3 4 5 6 7 8 9\n");if(rd()==1)break;}
	printf("done\n");std::fflush(stdout);
	return 0;
}