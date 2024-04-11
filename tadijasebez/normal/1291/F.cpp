#include <bits/stdc++.h>
using namespace std;

const int N=1025;
bool bad[N];
void Ask(int x){
	printf("? %i\n",x);
	fflush(stdout);
	char b[4];
	scanf("%s",b);
	if(b[0]=='Y')bad[x]=true;
}

void Reset(){
	printf("R\n");
	fflush(stdout);
}

int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	int sz=k==1?1:k/2;
	int m=n/sz;
	for(int st=1;st<=m/2;st++){
		int l=st,r=st-1;
		for(int i=0;i<m;i++){
			int g;
			if(i%2==0){
				r++;if(r>m)r=1;
				g=r;
			}else{
				l--;if(l==0)l=m;
				g=l;
			}
			for(int j=(g-1)*sz+1;j<=g*sz;j++)if(!bad[j])Ask(j);
		}
		Reset();
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(!bad[i])ans++;
	printf("! %i\n",ans);
	fflush(stdout);
	return 0;
}