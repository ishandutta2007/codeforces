#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	if (x<y){
		if (x+z<y){
			printf("-");
		}
		else{
			printf("?");
		}
	}
	else{
		if (x==y){
			if (z){
				printf("?");
			}
			else{
				printf("0");
			}
		}
		else{
			if (y+z<x){
				printf("+");
			}
			else{
				printf("?");
			}
		}
	}
	return 0; 
}