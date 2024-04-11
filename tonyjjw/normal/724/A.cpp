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

int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char buf1[100],buf2[100];

int day(char *buf){
	if(*buf == 'm') return 0;
	if(*buf == 't' && buf[1] == 'u') return 1;
	if(*buf == 'w') return 2;
	if(*buf == 't') return 3;
	if(*buf == 'f') return 4;
	if(*buf == 's' && buf[1] == 'a') return 5;
	return 6;
}

int main(){
	scanf("%s",buf1);
	scanf("%s",buf2);
	int d1 = day(buf1), d2 = day(buf2);
	int diff = d2 - d1;
	if(diff < 0) diff += 7;
	for(int i=0;i<11;i++){
		if(diff == days[i]%7){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}