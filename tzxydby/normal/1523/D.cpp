#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<time.h>
using namespace std;
#define R register int
bitset<200000>S[60];
bool c[60];
int main(){
	srand(time(0));
	int n,m,p,q;
	cin>>n>>m>>p;
	q=n-1>>1;
	string s;
	for(R i=0;i!=n;i++){
		cin>>s;
		for(R j=0;j!=m;j++){
			if(s[j]=='1'){
				S[j][i]=1;
			}
		}
	}
	vector<int>A,E;
	for(int i=0;i!=m;i++){
		c[i]=false;
		if(S[i].count()>q){
			A.push_back(i);
		}
	}
	if(A.empty()==true){
		for(R i=0;i!=m;i++){
			cout<<0;
		}
		return 0;
	}
	p=0;
	while(clock()<2950){
		bitset<200000>B=S[A[p]];
		vector<int>C,D;
		D.push_back(A[p]);
		for(R i=A.size()-1;i!=-1;i--){
			if(i!=p){
				C.push_back(A[i]);
			}
		}
		random_shuffle(C.begin(),C.end());
		for(vector<int>::iterator T=C.begin();T!=C.end();T++){
			if((B&S[*T]).count()>q){
				B&=S[*T];
				D.push_back(*T);
			}
		}
		if(D.size()>E.size()){
			E=D;
		}
		p++;
		if(p==A.size()){
			p=0;
		}
	}
	for(vector<int>::iterator T=E.begin();T!=E.end();T++){
		c[*T]=true;
	}
	for(R i=0;i!=m;i++){
		if(c[i]==true){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}