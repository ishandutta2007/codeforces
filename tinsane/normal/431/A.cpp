#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <iomanip>
#include<map>
#include <string>
#include<list>
#include<stack>
#include <queue>
using namespace std;


#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)



//#pragma comment(linker, "/STACK:167772160")

/*
int compare (const void* a, const void* b){
	return ((*(pair<int, int>*)b).first-(*(pair<int, int>*)a).first);

}*/


int main(){
	//ios_base::sync_with_stdio(0);
	int a[4], ans(0);
	for(int i(0); i<4; ++i)
		cin>>a[i];
	string s;
	cin>>s;
	for(int i(0);i<s.size(); ++i)
		ans+=a[s[i]-'1'];
	cout<<ans;
	return 0;
}