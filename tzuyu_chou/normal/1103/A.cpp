#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int ax[4]={1,2,3,4},ay[4]={1,1,1,1};
int bx[4]={1,3,1,3},by[4]={4,4,4,4};
int p,q;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(auto c:s){
		if(c=='1'){
			int cur=p;
			p=(p+1)%4;
			cout << ax[cur] << ' ' << ay[cur] << '\n';
		}
		else{
			int cur=q;
			q=(q+1)%4;
			cout << bx[cur] << ' ' << by[cur] << '\n';
		}
	}
}