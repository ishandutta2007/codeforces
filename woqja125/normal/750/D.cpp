#include<stdio.h>
int t[31];
bool map[2][320][320];
bool &M1(int x, int y){ return map[0][x+160][y+160]; }
bool &M2(int x, int y){ return map[1][x+160][y+160]; }
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%d", t+i);
	if(n%2 == 1){
		for(int i=1; i<=t[n]; i++) M1(0, i) = true;
		n-=2;
	}
	else{
		for(int i=1; i<=t[n-1]; i++) M1(0, i) = true;
		for(int j=1; j<=t[n]; j++) M1(-j, t[n-1]+j) = M1(j, t[n-1]+j) = true;
		n-=3;
	}
	auto *s = M2;
	auto *d = M1;
	for(; n>=1; n-=2){
		auto tm = s; s = d; d = tm;
		
	//	for(int i=-20; i<=20; i++,printf("\n"))for(int j=-15; j<=15; j++) printf("%d", s(i, j)?1:0);
//		printf("-------------");
		for(int i=-155; i<=155; i++)for(int j=-155; j<=155; j++) d(i,j) = false;

		for(int i=1; i<=t[n]; i++) d(0, i) = true;
		for(int i=1; i<=t[n+1]; i++) d(-i, t[n]+i) = d(i, t[n]+i) = true;
		
		for(int i=-155; i<=155; i++)for(int j=-155; j<=155; j++) if(s(i, j)){
			d(-t[n+1]+i, t[n]+t[n+1]+j)=d(t[n+1]+i, t[n]+t[n+1]+j)
				=d(-t[n+1]-j, t[n]+t[n+1]+i)=d(t[n+1]+j, t[n]+t[n+1]+i)=true;
		}
	}
//	for(int i=-20; i<=20; i++, printf("\n"))for(int j=-15; j<=15; j++) printf("%d", d(i, j)?1:0);
	int ans = 0;
	for(int i=-155; i<=155; i++)for(int j=-155; j<=155; j++) if(d(i, j)) ans++;
	printf("%d", ans);
	return 0;
}