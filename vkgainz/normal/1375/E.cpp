#include <bits/stdc++.h>
using namespace std;

int n, a[1001];
struct Inversion{
    int u,v;
    int a,b;
    Inversion(int x,int y,int w, int z){
        u = x; v = y;
        a = w; b = z;
    }

    //a and b represent the indexes of where they're at, u and v represent the values
    bool operator < (const Inversion& other) const{
        if(a != other.a) return a<other.a;

        if(v != other.v) return v>other.v; //does this do itin reverse?

        return b>other.b;
    }
    
};

void print(struct Inversion k){
    cout << (k.a+1) << " " << (k.b+1) << "\n";
}

vector<Inversion> pairs;
int main(){
   cin >> n;
   for(int i=0;i<n;i++){
       cin >> a[i];
   }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                pairs.push_back(Inversion(a[i],a[j],i,j));
            }
        }
    }
    cout << pairs.size() << endl;
    sort(pairs.begin(),pairs.end());
    for(auto x : pairs){
        print(x);
        
    }
   
}