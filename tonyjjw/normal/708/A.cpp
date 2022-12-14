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

void my_assert(bool c){
	if(!c) exit(0);
}

const int MN = 100000 + 1;

char buf[MN];

int main(){
	scanf("%s",buf);
	int L = strlen(buf);
	for(int i=0;i<L;i++){
		if(buf[i]!='a'){
			for(int j=i;j<L;j++){
				if(buf[j]=='a')break;
				buf[j]--;
			}
			printf("%s",buf);
			return 0;
		}
	}
	buf[L-1]='z';
	printf("%s",buf);
	return 0;
}