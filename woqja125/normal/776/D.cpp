#include<stdio.h>
#include<vector>
int s[100001][3];
int z[100001];
int p[200001];
int getp(int x){ return x==p[x]?x:p[x]=getp(p[x]); }
int uni(int a, int b){
	a=getp(a); b=getp(b);
	return p[a]=b;
}
int main(){
	int n, m, t, a, b;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", z+i);
	for(int i=0; i<m; i++){
		scanf("%d", &t);
		for(int j=1; j<=t; j++){
			scanf("%d", &a);
			s[a][++s[a][0]] = i;
		}
	}
	for(int i=0; i<2*m; i++) p[i] = i;
	for(int i=1; i<=n; i++){
		a=s[i][2]; b=s[i][1];
		if(z[i] == 0){
			uni(a*2, b*2+1);
			uni(a*2+1, b*2);
		}
		else{
			uni(a*2, b*2);
			uni(a*2+1, b*2+1);
		}
	}
	for(int i=0; i<m; i++){
		if(getp(i*2) == getp(i*2+1)){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}