#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string strs[55];

int main(){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>strs[i];
	int res=0;
	for(int i=0;i<N-1;i++) for(int j=0;j<M-1;j++){
		string str="";
		str+=strs[i][j];
		str+=strs[i][j+1];
		str+=strs[i+1][j];
		str+=strs[i+1][j+1];
		sort(str.begin(),str.end());
		if(str=="acef") res++;
	}
	cout<<res<<"\n";
	return 0;
}