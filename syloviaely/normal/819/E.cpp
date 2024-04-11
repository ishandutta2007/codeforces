#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
struct atom{
	vector<int>A;
	void print(){
		printf("%d ",A.size());
		for (int i=0;i<A.size();i++) printf("%d ",A[i]); printf("\n");
	}
};
vector<atom>A;
void put(int k1,int k2,int k3){
	atom k; k.A.push_back(k1); k.A.push_back(k2); k.A.push_back(k3); A.push_back(k);
}
void put(int k1,int k2,int k3,int k4){
	atom k; k.A.push_back(k1); k.A.push_back(k2); k.A.push_back(k3); k.A.push_back(k4); A.push_back(k);
}
int main(){
	scanf("%d",&n);
	if (n%2==0){
		put(1,2,3);
		put(1,2,4);
		put(2,3,4);
		put(1,3,4);
		for (int i=5;i<=n;i+=2){
			put(i,i+1,1);
			put(i,i+1,2);
			put(1,i,2,i+1);
			for (int j=3;j<i;j+=2)
				put(j,i,j+1,i+1),put(j,i,j+1,i+1);
		}
	} else {
		put(1,2,3); put(1,2,3);
		for (int i=4;i<=n;i+=2){
			put(1,i,3,i+1); put(2,i,3,i+1);
			put(i,i+1,1); put(i,i+1,2);
			for (int j=4;j<i;j+=2)
				put(j,i,j+1,i+1),put(j,i,j+1,i+1);
		}
	}
	printf("%d\n",A.size());
	for (int i=0;i<A.size();i++) A[i].print();
	return 0;
}