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
const int MOD=1e9+7,N=1e5+5;
const ll INF=1e11;
string s;
int a[4];
int r,b,y,g;
int main(){
	cin>>s;
	for (int i=0;i<s.size();i++)
	if (s[i]!='!')a[i%4]=s[i]-'A';
	for (int i=0;i<s.size();i++)
	if (s[i]=='!'){
		if (a[i%4]+'a'=='r')r++;
		if (a[i%4]+'a'=='b')b++;
		if (a[i%4]+'a'=='y')y++;
		if (a[i%4]+'a'=='g')g++;
	}
	cout<<r<<" "<<b<<" "<<y<<" "<<g<<endl;
    return 0;
}