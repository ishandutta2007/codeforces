#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> primes;

bool test(int n){
	printf("%d\n",n);
	fflush(stdout);
	char buf[10];
	scanf("%s",buf);
	if(*buf=='y')return true;
	return false;
}

int main(){
	for(int i=2;i<=100;i++){
		bool flag=true;
		for(int j=2;j<i;j++){
			if(i%j==0)flag=false;
		}
		if(flag) primes.push_back(i);
	}
	int p=-1;
	for(int i=0;i<primes.size();i++){
		if(primes[i]>10){
			return !printf("prime\n");
		}
		if(test(primes[i])){
			p=i;
			break;
		}
	}
	for(int i=p;i<primes.size() && primes[p] * primes[i] <= 100;i++){
		if(test(primes[p]*primes[i])){
			return !printf("composite\n");
		}
	}
	return !printf("prime\n");
}