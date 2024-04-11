/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,a[5010],b[5010],n;
ll res;
void mina(){
	scanf("%d",&n),res=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=0;
		for(int j=i+1;j<=n;j++)b[a[j]]++;
		for(int j=1;j<=n;j++)b[j]+=b[j-1];
		int sum=0;
		for(int j=i-1;j;j--){
			if(a[j]<a[i])res+=sum;
			sum+=b[a[j]-1];
		}
	}
	printf("%lld\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}