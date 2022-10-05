#include <bits/stdc++.h>
using namespace std;
int m,t;
vector <pair<pair <int,int> , int> > v;
bool Alloc(int x,int id){
	int i,j;
	for(i=0;i<m-x+1;i++){
		bool bad=false;
		for(j=0;j<v.size();j++){
			int a=v[j].first.first,b=v[j].first.second;
			if(a<i+x&&b>i)	bad=true; 
		}
		if(!bad){
			v.push_back(make_pair(make_pair(i,i+x),id));
			cout<<id<<endl;
			return true;
		}
	}
	cout<<"NULL"<<endl;
	return false;
}
bool ERASE(int id){
	int i;
	for(i=0;i<v.size();i++){
		if(v[i].second==id){
			v.erase(v.begin()+i);
			return true;
		}
	}
	return false;
}
void DEFRAGMENT(void){
	int i,sum=0;
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++){
		int x=v[i].first.second-v[i].first.first;
		v[i].first.first=sum;
		v[i].first.second=sum+x;
		sum+=x; 
	}
}
int main(){
	int x,i,id=1;
	cin>>t>>m;
	for(int e=0;e<t;e++){
		string s;
		cin>>s;
		if(s=="alloc"){
			cin>>x;
			if(Alloc(x,id))	id++;
		}
		else if(s=="erase"){
			cin>>x;
			if(!ERASE(x))	cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
		}
		else	DEFRAGMENT();	
	}
	return 0;
}