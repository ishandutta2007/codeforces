#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

char a[100], b[100];
char k[100], n[100];
int N;

int main(){
	scanf("%s%s",a,b);
	printf("%s %s\n",a,b);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s%s",k,n);
		if(!strcmp(a,k)){
			strcpy(a, n);
		}
		else{
			strcpy(b, n);
		}
		printf("%s %s\n", a,b);
	}
	return 0;
}