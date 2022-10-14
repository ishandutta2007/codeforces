#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,route[1010];
char cans[10];
int ans[1010];
bool getans(){
	cin>>cans;
	if(cans[0] == 'Y')return 1;
	return 0;
}
int main() {
	cin>>n;
	int x = n,y = n;
	for(int i=1;i<n;i++){
		cout<<"? 1 1 "<<x-1<<' '<<y<<endl;
		cout.flush();
		ans[n*2-2-i] = getans();
		if(ans[n*2-2-i]) x-=1;
		else y-=1;
	}
	int x2 = 1,y2 = 1;
	for(int i=0;i<n-1;i++){
		cout<<"? "<<x2<<' '<<y2+1<<' '<<n<<' '<<n<<endl;
		cout.flush();
		ans[i] = getans();
		if(ans[i]) y2+=1;
		else x2+=1;
		ans[i] = !ans[i];
	}
	cout<<"! ";
	for(int i=0;i<n*2-2;i++){
		if(ans[i])cout<<"D";
		else cout<<"R";
	}
	cout<<endl;
	cout.flush();
	return 0;
}