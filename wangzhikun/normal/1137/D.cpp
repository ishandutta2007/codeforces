#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
char ch[100];
int pos[10] = {0},act[10],k;
int t = 5,c = 1,cnt = 0;/*
void query(vector<int> cq){
	cnt+=1;
	cout<<"query:";
	for(auto i:cq) {
		pos[i]+=1;
		cout<<i<<' ';
	}
	cout<<endl;
	cout<<"pos:";
	for(int i=0;i<10;i++){
		cout<<pos[i]<<' ';
	}
	cout<<endl;
	map<int,int> alp;
	int cn = 1;
	cout<<"answer:";
	for(int i=0;i<10;i++){
		int cc = 0;
		if(pos[i]<t)cc = pos[i];
		else cc = (pos[i]-t)%c+t;
		if(alp[cc] == 0)alp[cc] = cn++;
		act[i] = alp[cc];
		cout<<act[i]<<' ';
	}
	cout<<endl;
}*/

void query(vector<int> cq){
	cout<<"next ";
	for(auto i:cq) {
		cout<<i<<' ';
		pos[i]+=1;
	}
	cout<<endl; cout.flush();
	cin>>k;
	for(int j=0;j<k;j++){
		cin>>ch;
		int n = strlen(ch);
		for(int i=0;i<n;i++)act[ch[i]-'0'] = j;
	}
}
int main() {
	for(int i=0;i<10000;i++){
		vector<int> cc;
		cc.push_back(0);
		if(i&1)cc.push_back(1);
		query(cc);
		if(act[0] == act[1])break;
	}
	int c = 0,t = 0;
	while(1){
		c+=1;
		vector<int> cc;
		cc.push_back(0);
		for(int j=2;j<=8;j++)cc.push_back(j);
		query(cc);
		if(act[0] == act[1]){
			break;
		}
	}
	
	while(1){
		t+=1;
		vector<int> cc;
		for(int j=2;j<=9;j++)cc.push_back(j);
		if(act[0] == act[2])cc.push_back(0);
		if(act[1] == act[2])cc.push_back(1);
		query(cc);
		if(act[2] == act[9]) break;
	}
	while(1){
		vector<int> cc;
		for(int j=0;j<=9;j++)if((pos[j]-t)%c!=0)cc.push_back(j);
		if(cc.size() == 0)break;
		query(cc);
	}
	cout<<"done"<<endl;cout.flush();
	//cout<<cnt<<endl;
	//for(int i=0;i<10;i++)cout<<"pos"<<i<<':'<<pos[i]<<endl;
	return 0;
}