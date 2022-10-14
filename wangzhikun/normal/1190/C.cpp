//determined
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}


int n,k;
set<int> blb,whb,blw,whw;
set<int>::iterator it;
char ch[100010];

void ins(int i){
	if(ch[i] == '1'){
		whw.insert(i);
		whb.insert(i);
	}else{
		blw.insert(i);
		blb.insert(i);
	}
}
void ers(int i){
	if(ch[i] == '1'){
		whw.erase(i);
		whb.erase(i);
	}else{
		blw.erase(i);
		blb.erase(i);
	}
}
bool chk(const set<int> &x){
	if(x.empty())return true;
	it = x.end();it--;
	if(*it-*x.begin()+1<=k)return true;
	return false;
}
int main(){
	read(n);read(k);
	cin>>ch;
	int win = 0;
	for(int i=0;i<n;i++){
		if(i<k){
			blb.insert(i);
			whw.insert(i);
		}else{
			ins(i);
		}
	}
	for(int i=0;i<=n-k;i++){
		if(whb.empty() || blw.empty()){
			cout<<"tokitsukaze"<<endl;
			return 0;
		}
		int cw2 = (chk(blb)|chk(whb))+(chk(blw)|chk(whw));
		//cout<<i<<' '<<cw2<<endl;
		if(cw2 == 2)win+=1;
		blb.erase(i);
		whw.erase(i);
		ins(i);
		if(i+k<n){
			ers(i+k);
			blb.insert(i+k);
			whw.insert(i+k);
		}
		
	}
	//cout<<win<<endl;
	if(win == n-k+1)cout<<"quailty"<<endl;
	else cout<<"once again"<<endl;
	return 0;
}