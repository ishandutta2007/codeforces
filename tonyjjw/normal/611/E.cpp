
//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 200000 + 1;

int N;
int A[MN];
int s[3];
int ans;
int p[8];
int dead[MN];

bool rev(int a,int b){
	return a>b;
}

void update(int a,int b,int c){
	int index = 4*a + 2*b + c;
	while(dead[p[index]] && p[index]<N) p[index]++;
}
bool chk(int a,int b,int c){
	int index = 4*a + 2*b + c;
	update(a,b,c);
	return p[index]<N;
}
void execute(int a,int b,int c){
	int index = 4*a + 2*b + c;
	update(a,b,c);
	if(chk(a,b,c)){
		dead[p[index]] = 1;
	}
}

void init(){
	for(int t=0;t<8;t++){
		int a = (t/4);
		int b = (t/2)%2;
		int c = t%2;
		int v = a*s[0] + b*s[1] + c*s[2];
		while(A[p[t]] > v && p[t] < N) p[t]++;
	}
}

int main(){
	scanf("%d",&N);
	scanf("%d%d%d",&s[0],&s[1],&s[2]);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(s,s+3);
	sort(A,A+N,rev);
	init();
	int a=s[0],b=s[1],c=s[2];
	for(int i=0;i<N;i++){
		if(dead[i])continue;
		if(b>=A[i]){
			execute(1,0,0);
			execute(0,1,0);
			execute(0,0,1);
		}
		else if(c>=A[i]){
			if(chk(1,0,0) && chk(0,1,0)){
				execute(1,0,0);
				execute(0,1,0);
				execute(0,0,1);
			}
			else{
				execute(0,0,1);
				execute(1,1,0);
			}
		}
		else if(a+b>=A[i]){
			execute(1,1,0);
			execute(0,0,1);
		}
		else if(a+c>=A[i]){
			execute(1,0,1);
			execute(0,1,0);
		}
		else if(b+c>=A[i]){
			execute(0,1,1);
			execute(1,0,0);
		}
		else if(a+b+c>=A[i]){
			execute(1,1,1);
		}
		else{
			puts("-1");
			return 0;
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}

//*/