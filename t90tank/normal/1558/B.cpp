#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std; 
const int maxn = 4000006; 

int n, m;
int f[maxn];  

int main() {
    cin>>n>>m;
    f[1] = 1;  
    for (int i = 2; i <= n; ++i) {
        if (i > 2) f[i] = (f[i]+f[i-1]) % m; // y=2~x-1, z=2~x-1  
        f[i] = (f[i]+f[i-1]) % m; // y=1
        f[i] = (f[i]+f[1]) % m;   // z=x
        for (int j = 2; i*j <= n; ++j)
            //x/j = i, (x-1)/j = i-1
            f[i*j] = (f[i*j]+(f[i]-f[i-1]) % m) % m; 
    }
    cout<<(f[n]+m) % m<<endl; 
}