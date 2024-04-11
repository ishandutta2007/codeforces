/*
Contest: Grakn Forces 2020
Problem: Codeforces 1408F
Author: tzc_wk
Time: 2020.10.1
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),vs=0;
vector<pii> ans;
vector<int> v[20];
inline void tk(int l1,int r1,int l2,int r2){
	fz(i,l1,r1){
		ans.pb(make_pair(i,i-l1+l2));
	}
}
int main(){
	int cur=1;
	for(int i=16;i>=0;i--){
		if(n>>i&1){
			for(int j=1;j<=i;j++){
				for(int k=cur;k<=cur+(1<<i)-1;k+=(1<<j)){
					tk(k,k+(1<<(j-1))-1,k+(1<<(j-1)),k+(1<<j)-1);
				}
			}
			vs++;
			for(int j=cur;j<=cur+(1<<i)-1;j++){
				v[vs].pb(j);
			}
			cur+=(1<<i);
		}
	}
	for(int i=vs;i>2;i--,vs--){
		int t1=v[vs].size(),t2=v[vs-1].size();
		while(t1<t2){
			for(int j=int(v[1].size()-1),k=0;k<t1;k++,j--){
				ans.pb(make_pair(v[1][j],v[vs][k]));
				v[vs].push_back(v[1][j]);v[1].pop_back();
			}
			t1<<=1;
		}
		for(int j=t1-1;j>=0;j--){
			ans.pb(make_pair(v[vs][j],v[vs-1][j]));
			v[vs-1].push_back(v[vs][j]);v[vs].pop_back();
		}
	}
	cout<<ans.size()<<endl;
	foreach(it,ans) cout<<it->fi<<" "<<it->se<<endl;
	return 0;
}