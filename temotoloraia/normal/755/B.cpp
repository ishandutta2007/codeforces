#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,x;
string s;
map<string,int>M;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s;
		M[s]++;
	}
	for (int i=1;i<=m;i++){
		cin>>s;
		if (M[s])x++;
	}
	if (x%2==0){
		if (n>m)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else {
		if (n>=m)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}