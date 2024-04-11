// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

int main() {
	int A,B;
	scanf(" %d %d",&A,&B);
	int xr =-1,yr =OVER9000;
	for(int j =0; j < 2; j++) {
		swap(A,B);
	vector<bool> c(A+B,true);
	int a =A, b =B-1;
	for(int i =1; i < A+B; i++) {
		if(a == 0) {
			b--;
			continue;}
		if(b == 0) {
			a--;
			c[i] =false;
			continue;}
		if(i%2 == 1) {
			c[i] =!c[i-1];
			if(c[i-1]) a--;
			else b--;}
		else {
			c[i] =c[i-1];
			if(c[i-1]) b--;
			else a--;}}
	int x =0, y =0;
	for(int i =1; i < A+B; i++) {
		if(c[i] == c[i-1]) x++;
		else y++;}
	if(xr < x) {
		xr =x;
		yr =y;}
	else if(xr == x) yr =min(yr,y);}
	printf("%d %d\n",xr,yr);
	return 0;}

// look at my code
// my code is amazing