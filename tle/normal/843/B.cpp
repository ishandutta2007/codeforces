#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <random>
#include <time.h>
using namespace std;


pair<int,int> arr[2111];
int m=0;

int n,start,x;


pair<int,int> ask(int ind){
	cout<<"? "<<ind<<endl;
	pair<int,int> ret;
	//ret.first=1;
	//ret.second=1;
	cin>>ret.first>>ret.second;
	if(ret.first == -1 && ret.second == -1){
		exit(0);
	}
	return ret;
}

void ans(int ind){
	cout<<"! "<<ind<<endl;

	exit(0);
}

int get_rand(){
	//long long r=rand();
	long long r= ((rand()*1ll*rand()%n) + rand()) %n;
	return r+1;
}

int main(){
	srand(time(0));
	
	cin>>n>>start>>x;
	m=1000;
	arr[0]=ask(start);
	
	if(arr[0].first >= x){
		ans(arr[0].first);
	}
	int ind=start,val=arr[0].first;
	
	for(int i=1;i<m;i++){
		//cout<<i<<" ";
		int xx=get_rand();
		arr[i]=ask(xx);
		arr[i].second =xx;
		if(arr[i].first < x){
			if(val < arr[i].first ){
				ind = xx;
				val = arr[i].first;
			}
		}
	}
	while(ind!= -1){
		pair<int,int> t = ask(ind);
		val = t.first;
		if(t.first >= x)break;
		ind = t.second;
		
	}
	if(ind ==-1){
		ans(-1);
	}
	ans(val);
	
}
//NOT MY PROGRAM