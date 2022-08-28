//CF 896A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const string f0 = " What are you doing at the end of the world? Are you busy? Will you save us?";
const string f1 = " What are you doing while sending `";
const string f2 = " `? Are you busy? Will you send `";
const string f3 = " `?";
const char C = '.';
const int N = 111111;
LL l0,l1,l2,l3,f[N];
char solve(int n,LL k){
	//cout<<n<<k<<endl;
	if(!n){
		if(k<=l0)
			return f0[k];
		else
			return C;
	}
	if(f[n]&&k>f[n])
		return C;
	char ch;
	if(k<=l1)
		return f1[k];
	k-=l1;
	ch=solve(n-1,k);
	if(ch!=C)
		return ch;
	k-=f[n-1];
	if(k<=l2)
		return f2[k];
	k-=l2;
	ch=solve(n-1,k);
	if(ch!=C)
		return ch;
	k-=f[n-1];
	if(k<=l3)
		return f3[k];
	return C;
}
int main()
{
	int T,n,i;
	char ch;
	LL k;
	l0=f0.length()-1;
	l1=f1.length()-1;
	l2=f2.length()-1;
	l3=f3.length()-1;
	//cout<<l0<<l1<<l2<<l3<<endl;
	f[0]=l0;
	for(i=1;i<=1e5;i=i+1){
		f[i]=l1+f[i-1]+l2+f[i-1]+l3;
		//cout<<f[i]<<endl;
		if(f[i]>1e18)
			break;
	}
	cin>>T;
	while(T--){
		cin>>n>>k;
		ch=solve(n,k);
		if(ch=='`')
			ch='"';
		cout<<ch;
	}
	return 0;
}
//What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?