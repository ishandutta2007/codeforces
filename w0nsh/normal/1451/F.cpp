#include <bits/stdc++.h>

int main(){
int t;
std::cin >> t;
while(t--){
int n,m;
std::cin >> n >> m;
std::vector<int> tab(n+m);
for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
int a;
std::cin >> a;
tab[i+j] ^= a;
}
std::cout << (tab == std::vector<int>(n+m) ? "Jeel\n" : "Ashish\n");
}

return 0;
}