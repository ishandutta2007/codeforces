// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N;
	scanf(" %d",&N);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	
	if(N <= 10) {
		for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) if(A[i] != A[j]) {
			swap(A[i],A[j]);
			bool inc =true, dec =true;
			for(int k =1; k < N; k++) {
				if(A[k-1] > A[k]) inc =false;
				if(A[k-1] < A[k]) dec =false;}
			if(!inc && !dec) {
				printf("%d %d\n",i+1,j+1); 
				return 0;}
			swap(A[i],A[j]);}
		printf("-1\n"); 
		return 0;}

	int mi =1000000000,mx =0;
	for(int i =0; i < N; i++) {
		mx =max(mx,A[i]);
		mi =min(mi,A[i]);}
	if(mi == mx) {printf("-1\n"); return 0;}
	vector<int> vmi,vmx;
	for(int i =0; i < N; i++) {
		if(mx == A[i]) vmx.push_back(i);
		if(mi == A[i]) vmi.push_back(i);}
	vmi.resize(min((int)vmi.size(),3));
	vmx.resize(min((int)vmx.size(),3));

	ALL_THE(vmi,it) ALL_THE(vmx,jt) {
		swap(A[*it],A[*jt]);
		bool inc =true, dec =true;
		for(int k =1; k < N; k++) {
			if(A[k-1] > A[k]) inc =false;
			if(A[k-1] < A[k]) dec =false;}
		if(!inc && !dec) {
			printf("%d %d\n",*it+1,*jt+1); 
			return 0;}
		swap(A[*it],A[*jt]);}
	printf("-1\n");
	return 0;}

// look at my code
// my code is amazing