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
const ll MOD=1e9+7,N=200001;
const ll INF=1e10;
int n,k;
int a,ans=1,fix[N];
int main(){
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		cin>>a;
		a%=(n-i+1);
		while (a>0){
			ans=ans%n+1;
			while (fix[ans])ans=ans%n+1;
			a--;
		}
		while (fix[ans])ans=ans%n+1;
		cout<<ans<<" ";
		fix[ans]=1;
		ans=ans%n+1;
		while (fix[ans])ans=ans%n+1;
	}
    return 0;
}