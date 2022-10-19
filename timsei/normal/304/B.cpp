using namespace std;
#include<bits/stdc++.h>
#define N 200001
int n , k;
void read(int &x) {
	char c = getchar();
	while(!isdigit(c)) c=getchar();
	x =0;
	while(isdigit(c)) {
		x*=10;x=x+c-'0';c=getchar();
	}
}
int y7 ,m1,d1,y2,m2,d2;
int ans = 0;
int m[13];
int main() {
	 m[1] =m[3]=m[5]=m[7]=m[8]=m[10]=m[12]=31;
	 m[2]=m[4]=m[6]=m[9]=m[11]=30;
	 m[2]-=2;
	read(y7);read(m1);read(d1);read(y2);read(m2);read(d2);
	if(y7 > y2) {
		swap(y7,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	if(y7==y2&&m1>m2) {
		swap(y7,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	if(y7==y2&&m1==m2&&d1>d2) {
		swap(y7,y2);
		swap(m1,m2);
		swap(d1,d2);		
	}
	if(y7==y2 && d1==d2 &&m1==m2) {
		puts("0");return 0;
	}
	for(int ans =0;ans <=100000000;ans ++) {
		d1++;
		if(m1 == 2 && (y7 % 4==0&&y7!=1900)) {
			if(d1 ==29) {
			if(y7==y2&&m1==m2&&d1==d2) {
			cout<<ans+1<<endl;break;
			}
			continue;
			}
			else if(d1 ==30) {
				m1++;d1 =1;
			}
		}
		if(d1==m[m1]+1) {
			d1=1;m1++;
		}
		if(m1==13) {
			y7++;m1=1;d1=1;
		}
		if(y7==y2&&m1==m2&&d1==d2) {
			cout<<ans+1<<endl;break;
		}
//		if(ans >50768)while(1);
	}
}