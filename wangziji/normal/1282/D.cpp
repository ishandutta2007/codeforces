#include <iostream>
using namespace std;
string A="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
string B="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; ;
int main(int argc, char** argv) {
	cout << A << endl;
	int x=0,y=0;
	cin >> x;
	if(!x) return 0;
	cout << B << endl;
	cin >> y;
	if(!y) return 0;
	int l=(600-x-y);
	string ans="";
	x=300-y;
	int CNT=0; 
	for(int i=1;i<l;i++)
	{
		A[i-1]='b';
		cout << A.substr(0,l) << endl;
		A[i-1]='a';
		int t;
		cin >> t;
		if(!t) return 0;
		if(t>=x)
			ans+='a';
		else
			ans+='b',++CNT;
	}
	if(CNT==300-y) 
		ans+='a';
	else
		ans+='b';
	cout << ans << endl;
	return 0;
}