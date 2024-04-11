#include<bits/stdc++.h>
using namespace std;


long long s , v1, t1 , v2, t2;
int main() {
	cin>>s>>v1>>v2>>t1>>t2;
	int p1 = s *v1 + 2 * t1;
	int p2 = s * v2 + 2 * t2;
	if(p1 < p2) {
		puts("First");return 0;
	}
	if(p1==p2) {
		puts("Friendship");return 0;
	}
	puts("Second");
}