#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=5000005;
const ll INF=1e9;
int n,c,d,x;
int maxx=INF,minn=-INF;
int main(){
	cin>>n;
	while (n--){
		cin>>c>>d;
		if (d==1)minn=max(minn,1900-x);
		else maxx=min(maxx,1899-x);
		x+=c;
	}
	if (minn>maxx){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if (maxx==INF){
		cout<<"Infinity"<<endl;
		return 0;
	}
	cout<<maxx+x<<endl;
    return 0;
}