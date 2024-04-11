#include <bits/stdc++.h>
#define ll long long
#define REP(i, a) for(int i = 0; i < a; i++)
 
using namespace std;
 
 
template<typename... T>
void rd(T&... args) {
	((cin >> args), ...);
}
int read() {
	int b; cin >> b;
	return b;
}
template<typename... T>
void write(T&... args) {
	((cout << args << " "), ...);
}
int main() 
{
    int n, dan = 0, anton=0; string b; rd(n, b);
    for(int i = 0; i < n; i ++ ) {
        if(b[i]=='D') dan++;
        else anton++;
    }
    if(dan==anton) write("Friendship");
    else if(dan>anton) write("Danik");
    else write("Anton");
    return 0;
}