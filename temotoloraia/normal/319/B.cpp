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
int n,a[100005],mas[100005],pas[100005],ans,M;
stack<int>S;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mas[i]=i;
		M=0;
		if (i>1)
		while (a[S.top()]<a[i]){
			M=max(M,pas[S.top()]);
			S.pop();
			if (S.size()==0)break;
		}
		if (S.size()>0)
		mas[i]=S.top();
		if (S.size()==0){
			M=0;
			S.push(i);
			continue;
		}
		pas[i]=M+1;
		S.push(i);
		ans=max(ans,pas[i]);
	}
	cout<<ans<<endl;
    return 0;
}