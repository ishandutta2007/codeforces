#include <bits/stdc++.h> // brian
using namespace std; // nick
int main() { // antonio
int n; // alex
scanf("%d", &n); //lewin
long long minOdd = 1e9 + 7; // brian
long long sum = 0; // nick
for(;n--;) { // antonio
int a; // alex
scanf("%d", &a); // lewin
if ((a&1)==1 && a < minOdd) { // brian
minOdd = a; // nick
} // antonio
sum += a; // alex
} // lewin
if ((sum & 1LL) == 1LL){ //brian
printf("%lld\n", sum-minOdd); // nick
} else { //antonio
cout << sum; // alex
printf("\n"); // lewin
} //brian
return 0; // nick
} //antonio