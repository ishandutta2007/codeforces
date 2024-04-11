#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char A[10],B[10];
char x[3][3];
char getin(){
	char ch=getchar();
	if (ch<'A'||ch>'Z') ch=getchar();
	//cout<<ch<<endl;
	return ch;
}
int main(){
	for (int i=1;i<=2;i++){
		for (int j=1;j<=2;j++) x[i][j]=getin();
	}
	int n=-1;
	if (x[1][1]!='X') A[++n]=x[1][1];
	if (x[1][2]!='X') A[++n]=x[1][2];
	if (x[2][2]!='X') A[++n]=x[2][2];
	if (x[2][1]!='X') A[++n]=x[2][1];
	for (int i=1;i<=2;i++){
		for (int j=1;j<=2;j++) x[i][j]=getin();
	}
	n=-1;
	if (x[1][1]!='X') B[++n]=x[1][1];
	if (x[1][2]!='X') B[++n]=x[1][2];
	if (x[2][2]!='X') B[++n]=x[2][2];
	if (x[2][1]!='X') B[++n]=x[2][1];
//	for (int i=0;i<3;i++) cout<<A[i]<<" "<<B[i]<<endl;
	for (int i=0;i<3;i++){
		int flag=0;
		for (int j=0;j<3;j++) if (A[j]!=B[(i+j)%3]) flag=1;
		if (flag==0) {
			cout<<"YES"<<endl; return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}