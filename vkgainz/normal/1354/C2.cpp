#include <bits/stdc++.h> 
using namespace std; 
  
const double pi = acos(-1.0); 
  
double nGon(int N) 
{ 
  
    double proAngleVar; 
  
    if (N % 4 == 0) { 
        proAngleVar 
            = pi * (180.0 / N) 
              / 180; 
    } 
    else { 
        proAngleVar 
            = pi * (180.0 / (2 * N)) 
              / 180; 
    } 
  
    double negX = 1.0e+99, 
           posX = -1.0e+99, 
           negY = 1.0e+99, 
           posY = -1.0e+99; 
  
    for (int j = 0; j < N; ++j) { 
  
        double px = cos(2 * pi * j / N 
                        + proAngleVar); 
  
        double py = sin(2 * pi * j / N 
                        + proAngleVar); 
  
        negX = min(negX, px); 
        posX = max(posX, px); 
        negY = min(negY, py); 
        posY = max(posY, py); 
    } 
  
    double opt2 = max(posX - negX, 
                      posY - negY); 
  
    return (double)opt2 
           / sin(pi / N) / 2; 
} 
  
int main() 
{ 

    int t;
    cin >> t;
    cout<<setprecision(9);
    while(t--){
        int n;
        cin >> n;
        n*=2;
        cout << nGon(n) << endl;
        
    }

}