#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

//std::vector<std::vector<int>> praz(100001);
std::vector<bool> isp(100001,false);

std::vector<int> p;
for(int i=2; i<=100000; i++){
    bool f=false;
    for(int j=0; j<p.size();j++) if(i%p[j]==0){
        f=true;
       
        //for(int k=0; k<praz[i/p[j]].size();k++) praz[i].push_back(praz[i/p[j]][k]);
        //praz[i].push_back(p[j]);
        break;
    }
    if(f) continue;
    p.push_back(i);
    isp[i]=true;
    //praz[i].push_back(i);
}

int n;
int ans=0;
cin >> n;
ans=n-1;
std::vector<int> u;

for(int k=n; k>n/2; k--){
    if(isp[k]) ans--;
}
cout<<ans/2<<endl;
ans/=2;
std::vector<bool> used(n+1,false);

for(int i=3; i<n/2; i++){
    if(isp[i]){
        int t=(n/(2*i))*(i);
        if((t%2)==0) t+=i;
        if(t<=(n/2)) t+=2*i;
        bool f=false;
        int fir;
        while((t)<=n){
            if(!used[t]){
                if(f){
                    cout<<fir<<" "<<t<<endl;
                    used[fir]=true;
                    used[t]=true;
                    f=false;
                    ans--;
                }
                else{
                    f=true;
                    fir=t;
                }
            }
            t+=2*i;

        }
        if(f){
            cout<<fir<<" "<<i<<endl;
            used[fir]=true;
            used[i]=true;
            ans--;
        }

    }
}
for(int i=3; i<=n/2; i+=2){
    if(used[i]==false){
        cout<<i<<" "<<2*i<<endl;
        used[i]=true;
        used[2*i]=true;
        ans--;
    }
}

int pt=2;
for(int i=0; i<ans; i++){
    while(used[pt]) pt+=2;
    int a=pt; pt+=2;
    while(used[pt]) pt+=2;
    cout<<a<<" "<<pt<<endl;
    pt+=2;
}
//cout<<s;

//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}