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
const int MOD=1e9+7,N=1000005;
const int INF=1e8;
string s,s1,s2;
int n,z[N],l,r;
int fix[N],fixx[N],maxx;
int ans;
int main(){
	cin>>s;
	n=s.size();
	z[0]=n;
	l=0;
	r=0;
	for (int i=1;i<n;i++){
		if (i<=r)z[i]=min(z[i-l],r-i+1);
		while (i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
		if (i+z[i]-1>r)r=i+z[i]-1,l=i;
		if (i+z[i]<n)maxx=max(maxx,z[i]);
		else maxx=max(maxx,z[i]-1),fix[z[i]]=1;
	}
	for (int i=maxx;i>=1;i--)
	if (fix[i]==1){
		ans=i;
		break;
	}
	if (ans==0){
		cout<<"Just a legend"<<endl;
		return 0;
	}
	for (int i=0;i<ans;i++)cout<<s[i];
    return 0;
}