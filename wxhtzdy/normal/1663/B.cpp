#include <bits/stdc++.h>
using namespace std;
vector<int> r={1200,1400,1600,1900,2100,2300,2400,2600,3000};
int main() {
	int n;
	scanf("%d",&n);
	int ptr=r.size()-1;
	while (ptr>0&&r[ptr-1]>n) ptr--;
	printf("%d",r[ptr]);
}