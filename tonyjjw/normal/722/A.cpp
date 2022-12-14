#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

char buf[10];
char str[10];
char ans[10];

int dist(){
	int cnt=0;
	for(int i=0;i<5;i++) if(buf[i]!=str[i]) cnt++;
	return cnt;
}

bool correct(int tp){
	int hr = 10*(str[0]-'0')+(str[1]-'0');
	int min = 10*(str[3]-'0')+(str[4]-'0');
	if(min>=60) return false;
	if(tp == 12){
		return 1 <= hr && hr <= 12;
	}
	else{
		return 0 <= hr && hr <= 23;
	}
}

int main(){
	II(tp);
	scanf("%s",buf);
	str[2]=':';
	int al = 100;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)for(int k=0;k<10;k++)for(int l=0;l<10;l++){
		str[0]=i+'0';
		str[1]=j+'0';
		str[3]=k+'0';
		str[4]=l+'0';
		if(correct(tp) && dist() < al){
			al = dist();
			strcpy(ans, str);
		}
	}
	printf("%s",ans);
	return 0;
}