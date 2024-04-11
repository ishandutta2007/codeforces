
//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char s1[100],s2[100];
int n;
int mon,day;
int type;
int ans;

void calc2(){
	if(day==n)ans++;
	if(day==days[mon-1]){
		day=1;
		mon++;
	}
	else{
		day++;
	}
}

void calc1(){
	if(day==n)ans++;
	day++;
	if(day==8)day=1;
}

int main(){
	scanf("%d %s %s",&n,&s1,&s2);
	if(*s2 == 'w'){
		type=1;
		day = 5;
		for(int i=0;i<366;i++)calc1();
	}
	else{
		mon = 1,day = 1;
		while(mon<13)calc2();
	}
	printf("%d\n",ans);

	return 0;
}

//*/