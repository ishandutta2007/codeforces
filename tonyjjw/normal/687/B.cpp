#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}

int N,K;

int main(){
	scanf("%d%d",&N,&K);
	ll v=0;
	for(int i=0;i<N;i++){
		II(a);
		if(i==0) v=a;
		else v=lcm(v,(ll)a);
		v=gcd(v,(ll)K);
	}
	if(v==K){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}